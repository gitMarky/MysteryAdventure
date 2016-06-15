
protected func Initialize()
{
	if (!GetEffect("IntBurning", this)) AddEffect("IntBurning", this, 100, 1, this);
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
		DampingX = 600,
		Alpha = PV_KeyFrames(1000, 0, 0, 700, 255, 1000, 0),
		Size = PV_Linear(PV_Random(15, 20), PV_Random(20, 30))
	};
	// Set the light range for this torch.
	SetLightRange(100, 80);
	SetLightColor(FIRE_LIGHT_COLOR);
	return 1;
}

private func FxIntBurningTimer (object target, effect fx, int time)
{
	// Smoke effects.
	CreateParticle("Smoke", PV_Random(-3, 3), PV_Random(0, -2), PV_Random(-2, 2), PV_Random(-2, 2), 60 + Random(30), fx.smoke, 1);
	// Fire effects.
	CreateParticle("FireSharp", PV_Random(-5, 5), PV_Random(7, 0), PV_Random(-2, 2), PV_Random(-2, -3), 18 + Random(5), fx.flame, 6);
	CreateParticle("FireSharp", PV_Random(-2, 2), PV_Random(2, -2), PV_Random(-2, 2), PV_Random(-5, -9), 10 + Random(5), fx.flame, 4);

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
