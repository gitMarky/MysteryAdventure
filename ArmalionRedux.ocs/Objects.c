/* Manually created objects file */


func InitializeObjects()
{
	CreateCastle();
	CreateBarrels();
	return true;
}

func CreateCastle()
{
	var colormod = RGB(180, 180, 180);
	var castle_parts = [];
	
	// 483, 543, 603, 633 (Hall), 663

	// Main hall

	var hall1 = CreateObject(CPH1,  41, 633, NO_OWNER);
	var hall2 = CreateObject(CPH1, 121, 633, NO_OWNER);
	var hall3 = CreateObject(CPH1, 201, 633, NO_OWNER);
	hall1.Plane -= 200;
	hall2.Plane -= 200;
	hall3.Plane -= 200;
	
	PushBack(castle_parts, hall1);
	PushBack(castle_parts, hall2);
	PushBack(castle_parts, hall3);
	
	// 3rd floor
	
	PushBack(castle_parts, CreateObject(CPW1,  21, 483, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 141, 483, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 261, 483, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW2, 201, 483, NO_OWNER));	// Alchemist lab
	PushBack(castle_parts, CreateObject(CPW2,  81, 483, NO_OWNER));	// Workshop

	CreateCastleFloor(21, 261, 483);
	PushBack(castle_parts, CreateObject(Castle_Tower_Right, 261, 483, NO_OWNER));

	// 2nd floor
	
	PushBack(castle_parts, CreateObject(CPW1,  21, 543, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1,  61, 543, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW2, 121, 543, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 261, 543, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 381, 543, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW2, 201, 543, NO_OWNER));	// Kitchen
	
	CreateCastleFloor( 21, 261, 543);
	CreateCastleFloor(381, 381, 543);
	PushBack(castle_parts, CreateObject(Castle_Tower_Middle, 261, 543, NO_OWNER));
	PushBack(castle_parts, CreateObject(Castle_Tower_Right, 381, 543, NO_OWNER));

	// 1st floor
	
	PushBack(castle_parts, CreateObject(CPW1, 261, 603, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW2, 321, 603, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 381, 603, NO_OWNER));

	CreateCastleFloor(21, 381, 603);
	PushBack(castle_parts, CreateObject(Castle_Wall_Left, 261, 603, NO_OWNER));
	PushBack(castle_parts, CreateObject(Castle_Tower_Middle, 381, 603, NO_OWNER));


	// Ground floor

	PushBack(castle_parts, CreateObject(CPW1, 261, 663, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW2, 321, 663, NO_OWNER)); // Kontor
	PushBack(castle_parts, CreateObject(CPW1, 381, 663, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 421, 663, NO_OWNER));

	CreateCastleFloor(261, 421, 663);

	PushBack(castle_parts, CreateObject(Castle_Tower_Middle, 421, 663, NO_OWNER));

	
	PushBack(castle_parts, CreateObject(CPW1, 538, 663, NO_OWNER)); // Tower in the front 
	CreateCastleFloor(538, 538, 663);
	PushBack(castle_parts, CreateObject(Castle_Tower_Middle, 538, 663, NO_OWNER));


	// Town gate tower
	
	PushBack(castle_parts, CreateObject(CPW1, 1585, 743, NO_OWNER));
	CreateCastleFloor(1585, 1585, 743);
	PushBack(castle_parts, CreateObject(Castle_Tower_Middle, 1585, 743, NO_OWNER));

	// Color objects
	for (var castle_part in castle_parts) castle_part->SetClrModulation(colormod);
	
	// Plane
	for (var obj in FindObjects(Find_InRect(20, 480, 4, 185))) obj.Plane -= 200;
	
	
	// Torches
	
	CreateObject(Castle_Torch, 126, 554, NO_OWNER)->SetLeft()->SwitchOn();
	CreateObject(Castle_Torch, 313, 615, NO_OWNER)->SetLeft()->SwitchOn();
	CreateObject(Castle_Torch, 295, 685, NO_OWNER)->SetLeft()->SwitchOn();
	CreateObject(Castle_Torch, 347, 685, NO_OWNER)->SetRight()->SwitchOn();
	CreateObject(Castle_Torch, 115, 812, NO_OWNER)->SetLeft()->SwitchOn();
	CreateObject(Castle_Torch, 248, 955, NO_OWNER)->SetLeft()->SwitchOn();
	
	// Gobelins
	
	CreateObject(Castle_Gobelin, 121, 625, NO_OWNER);
	CreateObject(Castle_Gobelin, 198, 625, NO_OWNER);
}


func CreateCastleFloor(int x_start, int x_end, int y)
{
	for (var x = x_start; x <= x_end; x += 40)
	{
		CreateObject(Castle_Floor, x, y, NO_OWNER);
	}
}


func CreateBarrels()
{
	var barrels = [];
	var large_barrels = [];
	
	PushBack(large_barrels, CreateObject(Dummy, 37, 835, NO_OWNER));
	PushBack(large_barrels, CreateObject(Dummy, 58, 835, NO_OWNER));
	PushBack(large_barrels, CreateObject(Dummy, 84, 835, NO_OWNER));
	
	var barrel1 = CreateObject(Dummy, 80, 844, NO_OWNER);
	var barrel2 = CreateObject(Dummy, 86, 844, NO_OWNER);
	barrel1->SetClrModulation(RGB(240, 240, 240));
	barrel2->SetClrModulation(RGB(200, 200, 200));
	PushBack(barrels, barrel1);
	PushBack(barrels, barrel2);
	PushBack(barrels, CreateObject(Dummy, 94, 844, NO_OWNER));

	PushBack(barrels, CreateObject(Dummy, 1898, 766, NO_OWNER));
	PushBack(barrels, CreateObject(Dummy, 1901, 773, NO_OWNER));
	PushBack(barrels, CreateObject(Dummy, 1895, 773, NO_OWNER));
	
	var barrel3 = CreateObject(Dummy, 2782, 505, NO_OWNER);
	barrel3->SetR(-16);
	PushBack(barrels, barrel3);
	PushBack(barrels, CreateObject(Dummy, 2790, 505, NO_OWNER));
	
	// set barrels to 8x10
	for (var barrel in barrels)
	{
		barrel->SetObjDrawTransform(800, 0, 0, 0, 750);
		barrel->SetShape(-4, -5, 8, 10);
		barrel->SetGraphics(nil, Barrel);
		barrel.Visibility = VIS_All;
	}
	
	for (var barrel in large_barrels)
	{
		barrel->SetObjDrawTransform(2000, 0, 0, 0, 2000);
		barrel->SetShape(-9, -9, 18, 18);
		barrel->SetGraphics(nil, Barrel);
		barrel.Visibility = VIS_All;
		barrel.MeshTransformation = Trans_Mul(Trans_Rotate(90, 1, 0, 0), Trans_Rotate(-10, 0, 0, 1));
		barrel->SetClrModulation(RGB(150, 150, 150));
	}
}