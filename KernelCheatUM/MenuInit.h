int InitializeStyle = 0;
bool MenuShow = true;
void load_styles()
{
    ImVec4* colors = ImGui::GetStyle().Colors;
    {

        colors[ImGuiCol_Text] = ImVec4(0.92f, 0.92f, 0.92f, 1.00f);
        colors[ImGuiCol_TextDisabled] = ImVec4(0.44f, 0.44f, 0.44f, 1.00f);
        colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
        colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
        colors[ImGuiCol_Border] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_FrameBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
        colors[ImGuiCol_FrameBgHovered] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_FrameBgActive] = ImVec4(1.000f, 0.000f, 0.365f, 0.818f);
        colors[ImGuiCol_TitleBg] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_TitleBgActive] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
        colors[ImGuiCol_MenuBarBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
        colors[ImGuiCol_ScrollbarBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.53f);
        colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.47f, 0.47f, 0.47f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.81f, 0.83f, 0.81f, 1.00f);
        colors[ImGuiCol_CheckMark] = ImVec4(1.000f, 0.000f, 0.365f, 0.818f);
        colors[ImGuiCol_SliderGrab] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_SliderGrabActive] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_Button] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);;
        colors[ImGuiCol_ButtonHovered] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_ButtonActive] = ImVec4(1.000f, 0.000f, 0.365f, 0.818f);
        colors[ImGuiCol_Header] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_HeaderHovered] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_HeaderActive] = ImVec4(0.93f, 0.65f, 0.14f, 1.00f);
        colors[ImGuiCol_Separator] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
        colors[ImGuiCol_SeparatorHovered] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_SeparatorActive] = ImVec4(1.000f, 0.000f, 0.365f, 0.818f);
        colors[ImGuiCol_ResizeGrip] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
        colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_ResizeGripActive] = ImVec4(1.000f, 0.000f, 0.365f, 0.818f);;
        colors[ImGuiCol_Tab] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_TabHovered] = ImVec4(0.040f, 0.298f, 0.008f, 1.000f);
        colors[ImGuiCol_TabActive] = ImVec4(1.000f, 0.000f, 0.365f, 0.818f);
        colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
        colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
        colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
        colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
        colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
        colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
        colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
        colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
        colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
        colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);


        InitializeStyle = 1;
    }

}


int InitializeMenus;
void TerInitRender(IDirect3DDevice9* a1) {


    ImGui::CreateContext();


    ImGui_ImplWin32_Init(FindWindowA(xor_a("CrossFire"),0));
    ImGui_ImplDX9_Init(a1);

    if (!InitializeStyle)
        load_styles();

    InitializeMenus = true;

}


void TerCleanMenu() {

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();


}


void TerInitMenu() {

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    if (!InitializeStyle)
        load_styles();

    ImGui::GetIO().MouseDrawCursor = MenuShow;
}


void TerFinishMenu() {

    ImGui::End();
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

}


