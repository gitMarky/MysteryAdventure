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
	
	// 603, 633 (Hall), 663

	PushBack(castle_parts, CreateObject(CPH1,  41, 632, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPH1, 121, 632, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPH1, 201, 632, NO_OWNER));
	
	PushBack(castle_parts, CreateObject(CPW1, 141, 480, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 261, 543, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 381, 541, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 381, 602, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 261, 482, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 421, 663, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 538, 663, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW1, 1585, 743, NO_OWNER));
	
	PushBack(castle_parts, CreateObject(CPW2, 321, 602, NO_OWNER));
	PushBack(castle_parts, CreateObject(CPW2, 121, 540, NO_OWNER));
	
	// Kontor
	PushBack(castle_parts, CreateObject(CPW2, 321, 663, NO_OWNER));
	
	// Kitchen
	PushBack(castle_parts, CreateObject(CPW2, 201, 542, NO_OWNER));
	
	// Alchemist lab
	PushBack(castle_parts, CreateObject(CPW2, 201, 481, NO_OWNER));
	
	// Workshop
	PushBack(castle_parts, CreateObject(CPW2, 81, 480, NO_OWNER));
	
	for (var castle_part in castle_parts) castle_part->SetClrModulation(colormod);
}