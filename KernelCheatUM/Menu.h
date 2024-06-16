#pragma once


bool TerESPSkeleton;
void TerDrawMenu(IDirect3DDevice9*) {


	ImGui::SetNextWindowSize({ 280.f,170.f });
	ImGui::Begin(xor_a("[CFBR] External FRCHEATS"), 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);


	 if (ImGui::CollapsingHeader(xor_a("ESP"))) {
		ImGui::SetCursorPos({ 10.f,80.f });
		ImGui::Checkbox(xor_a("ESP Caixa"), &ESPDrawBox);
		ImGui::SetCursorPos({ 140.f,80.f });
		ImGui::Checkbox(xor_a("ESP Vida"), &ESPHealth);
		ImGui::SetCursorPos({ 10.f,110.f });
		ImGui::Checkbox(xor_a("ESP Nome"), &ESPName);
		ImGui::SetCursorPos({ 140.f,110.f });
		ImGui::Checkbox(xor_a("ESP Linha"), &ESPLine);
	 }



	ImGui::End();




}





IDirect3DDevice9* m_TerDevice;
void TerRenderMenu(IDirect3DDevice9* TerDevice) {

	if (TerDevice != m_TerDevice) {

		if (InitializeMenus) TerCleanMenu();
		m_TerDevice = TerDevice;
	}




	if (GetAsyncKeyState(0x79) & 1)
		MenuShow = !MenuShow;


	if (TerDevice) {

		TerInitMenu();

		if (MenuShow)
		TerDrawMenu(TerDevice);

		PlayerESP();
		TerFinishMenu();

	}





}

