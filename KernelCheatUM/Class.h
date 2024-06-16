

struct Transform
{
	D3DXVECTOR3 Pos;
	char Spacer[256];
};


class CharactherFx
{
public:
	char _0x0000[564];
	__int32 IsDead; //0x0234 
	char _0x0238[12];
	BYTE Respawn; //0x0244 
	char _0x0248[1528];

};//Size=0x0840


class CObject
{
public:
	DWORD64 Unk;
	D3DXVECTOR3 Body;
	D3DXVECTOR3 Foot;
};



class cPlayer
{
public:
	union
	{
		CObject* Object;
		int* iObject; //0x0000 
	};
	char _0x0008[1];
	BYTE Time;//0x0006
	char Name[12]; //0x000A 
	char _0x0016[2];
	CharactherFx pCharactherFx; //0x0018 
	__int32 Index; //0x0020 	
	int unk;
	int c4;
	char _0x0024[32];
	__int32 Vida; //0x0044 
	__int32 Kills; //0x0048 
	char _0x004C[1012];

};//Size=0x0440




