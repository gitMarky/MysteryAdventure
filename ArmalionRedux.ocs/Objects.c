/* Manually created objects file */


func InitializeObjects()
{
	CreateCastle();
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
	hall1.Plane = -1;
	hall2.Plane = -1;
	hall3.Plane = -1;
	
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
}


func CreateCastleFloor(int x_start, int x_end, int y)
{
	for (var x = x_start; x <= x_end; x += 40)
	{
		CreateObject(Castle_Floor, x, y, NO_OWNER);
	}
}