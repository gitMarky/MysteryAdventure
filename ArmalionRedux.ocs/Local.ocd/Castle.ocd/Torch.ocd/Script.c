/**
	Torch
	
	@author Pyrit, Maikel
 --*/

protected func Initialize()
{
	CASTLE_TORCH_ROT_SCREEN = Trans_Rotate(-20, 1, 0, 0);
	CASTLE_TORCH_ROT_LEFT = Trans_Rotate(-10, 0, 0, 1);
	CASTLE_TORCH_ROT_RIGHT = Trans_Rotate(+10, 0, 0, 1);


	// Rotate the head of the torch a little into the screen.
	this.MeshTransformation = CASTLE_TORCH_ROT_SCREEN;
	SetMeshMaterial("Castle_Torch");
	return;
}


// Returns whether the torch currently is a source of light.
public func IsLightSource()
{
	return !!GetEffect("IntBurning", this);
}


/*-- Usage --*/

public func SetLeft()
{
	this.MeshTransformation = Trans_Mul(CASTLE_TORCH_ROT_SCREEN, CASTLE_TORCH_ROT_LEFT);
	return this;
}

public func SetRight()
{
	this.MeshTransformation = Trans_Mul(CASTLE_TORCH_ROT_SCREEN, CASTLE_TORCH_ROT_RIGHT);
	return this;
}


public func ControlUse(object clonk)
{
	if (IsLightSource())
	{
		SwitchOff();
	}
	else
	{
		SwitchOn();
	}
	return true;
}

public func IsInteractable(object clonk)
{
	return interactable;
}

func GetInteractionMetaInfo(object clonk)
{
	return { Description = "$MsgTorchDetach$", IconName = nil, IconID = nil, Selected = false };
}


public func SwitchOn()
{
	// Add a burning effect if not already done.
	if (!GetEffect("IntBurning", this))
		AddEffect("IntBurning", this, 100, 1, this);
	return this;
}

public func SwitchOff()
{
	// Remove the burning effect if active.
	if (!GetEffect("IntBurning", this))
		RemoveEffect("IntBurning", this);
	return this;
}


/*-- Burning Effect --*/

private func FxIntBurningStart(object target, effect fx, int temporary)
{
	if (temporary)
		return 1;
	// Ensure the interval is always one frame.
	fx.Interval = 1;
	// Fire particle
	fx.flame = 
	{
		R = PV_KeyFrames(0, 0, 0, 200, 255, 800, 255, 1000, 255),
		G = PV_KeyFrames(0, 0, 0, 200, 210, 800, 70, 1000, 70),
		B = PV_KeyFrames(0, 0, 255, 200, 100, 800, 0, 1000, 0),
		
		Alpha = PV_KeyFrames(1000, 0, 0, 10, 255, 500, 255, 1000, 0),
		Size = PV_Linear(PV_Random(2, 3), PV_Random(4, 5)),
		Stretch = 1000,
		Phase = PV_Random(0, 4),
		Rotation = PV_Random(0, 359),
		DampingX = 900,
		DampingY = 1000,
		BlitMode = GFX_BLIT_Additive,
		CollisionVertex = 0,
		OnCollision = PC_Die(),
		Attach = ATTACH_Front
	};
	fx.smoke = 
	{
		Prototype = Particles_Smoke(),
		Size = PV_Linear(PV_Random(2, 3), PV_Random(3, 5))
	};
	// Set the light range for this torch.
	SetLightRange(80, 60);
	SetLightColor(FIRE_LIGHT_COLOR);
	return 1;
}

private func FxIntBurningTimer (object target, effect fx, int time)
{
	// If the torched is attached or fixed it should emit some fire and smoke particles.

	// Fire effects.
	CreateParticle("FireSharp", PV_Random(-1, 2), PV_Random(0, -3), PV_Random(-2, 2), PV_Random(-3, -5), 10 + Random(3), fx.flame, 8);
	// Smoke effects.
	CreateParticle("Smoke", PV_Random(-1, 2), PV_Random(-7, -9), PV_Random(-2, 2), PV_Random(-2, 2), 24 + Random(12), fx.smoke, 2);

	return 1;
}

protected func FxIntBurningStop(object target, proplist effect, int reason, bool temporary)
{
	if (temporary)
		return 1;
	// Remove the light from this torch.	
	SetLightRange(0);
	return 1;
}

public func SaveScenarioObject(proplist props, ...)
{
	if (!_inherited(props, ...)) return false;
	return true;
}


/*-- Properties --*/

protected func Definition(def) 
{
	SetProperty("PictureTransformation", Trans_Mul(Trans_Translate(2500, -1500, 0), Trans_Rotate(-30, 0, 0, 1)), def);
}

local Name = "$Name$";
local Description = "$Description$";
local interactable = false;

local CASTLE_TORCH_ROT_SCREEN;
local CASTLE_TORCH_ROT_LEFT;
local CASTLE_TORCH_ROT_RIGHT;

