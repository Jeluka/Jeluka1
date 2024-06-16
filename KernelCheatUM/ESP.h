#pragma once
bool ESPDrawBox, ESPName, ESPLine,ESPHealth;
bool NoRecoil, CrossHair, NoFallDamage, BagHack;
//WPM wrapper - Lets us call WriteProcessMemory MUCH more easily (with less args)
template <class dataType>
void wpm(dataType valToWrite, DWORD64 addressToWrite)
{
	WriteProcessMemory(hProc, (PVOID64)addressToWrite, &valToWrite, sizeof(dataType), 0);
}

//RPM wrapper - Lets us call ReadProcessMemory MUCH more easily (with less args)
template <class dataType>
dataType rpm(DWORD64 addressToRead)
{
	//Stores the value of the address being read
	dataType rpmBuffer;

	//RPM
	ReadProcessMemory(hProc, (PVOID64)addressToRead, &rpmBuffer, sizeof(dataType), 0);

	//Return the value that was read
	return rpmBuffer;
}




#define ClientShell 0x2DD1520
#define FirstPlayerOffs 0x2DD17A8
#define MePlayerOffs 0x2DD17A2
#define PlayerSize 0x2080

cPlayer GetPlayerStruct(int i) {
	return Read<cPlayer>(CShell_address + FirstPlayerOffs + (i * PlayerSize));
}




void PlayerESP() {


	for (int i = 0; i < 16; i++)
	{

		BYTE myIdx = Read<BYTE>(CShell_address + MePlayerOffs);

		CObject* MePlayerObject = Read<CObject*>((uintptr_t)CShell_address + FirstPlayerOffs + (myIdx * PlayerSize));
		CObject* PlayerObject = Read<CObject*>((uintptr_t)CShell_address + FirstPlayerOffs + (i * PlayerSize));

		CharactherFx* pCharacther = Read<CharactherFx*>((uintptr_t)CShell_address + FirstPlayerOffs + 0x18 + (i * PlayerSize));

		int IsDead = Read<int>((uintptr_t)pCharacther + 0x23C);
		BYTE IsRespawn = Read<BYTE>((uintptr_t)pCharacther + 0x24C);

		int EnemyHealth = Read<int>(CShell_address + FirstPlayerOffs + 0x44 + (i * PlayerSize));

		cPlayer curP = GetPlayerStruct(i);
		cPlayer MecurP = GetPlayerStruct(myIdx);


		RGBA Color = Red;




	   if (PlayerObject == 0)
		   continue;

	   if (IsDead)
		   continue;


	   if (IsRespawn)
		   Color = Green2;


	   if (curP.Time == MecurP.Time)
		   continue;

	   if (curP.c4)
		   Color = Green;


		D3DXVECTOR3 CenterPos, HeadPos, FootPos;

         CenterPos = Read<D3DXVECTOR3>((uintptr_t)PlayerObject + 0x19C);
		 HeadPos = Read<D3DXVECTOR3>((uintptr_t)PlayerObject + 0x14);

		 




		if (EngineW2S(&CenterPos) && EngineW2S(&HeadPos) && EngineW2S(&FootPos)) {
		
			FootPos.x = CenterPos.x;
			FootPos.z = CenterPos.z;
			HeadPos.x = CenterPos.x;
			HeadPos.z = CenterPos.z;

			D3DXVECTOR3 Box = HeadPos - FootPos;

			if (Box.y < 0)
				Box.y *= -1;

			int BoxWidth = (int)Box.y / 2;
			int DrawX = (int)HeadPos.x - (BoxWidth / 2);
			int DrawY = (int)HeadPos.y ;

			RGBA dwColor1{ 0,0,0,0 };



		
			if (ESPDrawBox) {
				DrawRect(DrawX - 5, DrawY - 5, BoxWidth + 10, Box.y + 10, &Color, 1.5f);
			}
			if (ESPName) {
				DrawStrokeText(DrawX, DrawY - 14, &Yellow, curP.Name);
			}
			if (ESPLine) {
				DrawLine(DrawX, DrawY, viewport.Width / 2, viewport.Height, &White, 1.5f);
			}

			
	 }

			
	}
}

