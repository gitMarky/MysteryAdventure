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

	// main hall
	var hall1 = CreateObject(CPH1,  41, 633, NO_OWNER);
	var hall2 = CreateObject(CPH1, 121, 633, NO_OWNER);
	var hall3 = CreateObject(CPH1, 201, 633, NO_OWNER);
	hall1.Plane = -1;
	hall2.Plane = -1;
	hall3.Plane = -1;
	
	PushBack(castle_parts, hall1);
	PushBack(castle_parts, hall2);
	PushBack(castle_parts, hall3);
	
	// 
	
	PushBack(castle_parts, CreateObject(CPW1, 141, 483, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 261, 483, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW2, 201, 483, NO_OWNER));	// Alchemist lab
	PushBack(castle_parts, CreateObject(CPW2, 81, 483, NO_OWNER));	// Workshop

	//
	
	PushBack(castle_parts, CreateObject(CPW2, 121, 543, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 261, 543, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 381, 543, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW2, 201, 543, NO_OWNER));	// Kitchen
	
	PushBack(castle_parts, CreateObject(CPW2, 321, 603, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 381, 603, NO_OWNER));
	
	PushBack(castle_parts, CreateObject(CPW1, 421, 663, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 538, 663, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW2, 321, 663, NO_OWNER)); 	// Kontor

	PushBack(castle_parts, CreateObject(CPW1, 1585, 743, NO_OWNER));
	
	for (var castle_part in castle_parts) castle_part->SetClrModulation(colormod);
}