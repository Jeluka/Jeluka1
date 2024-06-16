#include "framework.h"
#include <thread>
#include <iostream>

void TitleThread() {
    while (true) {
        SetConsoleTitleA(random_string().c_str());
    }
}

std::thread Title(TitleThread);
int Enable;
DWORD64 Check = NULL;
int main() {
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
    Title.detach();

    std::cout << "Iniciando o programa..." << std::endl;

    std::cout << "Verificando se CrossFire ou DIEmWin estão ativos..." << std::endl;
    while (!FindWindowA(xor_a("CrossFire"), 0) && !FindWindowA(xor_a("DIEmWin"), xor_a("DIEmWin"))) {
        std::cout << "Aguardando por CrossFire..." << std::endl;
        Sleep(123);
    }

    std::cout << "Obtendo ID do processo de CrossFire..." << std::endl;
    process_id = get_process_id(xor_a("crossfire.exe"));
    CFBase = get_module_base_x64(xor_a("crossfire.exe"));

    if (!CFBase) {
        std::cout << "Falha ao encontrar o módulo base de CrossFire. Saindo..." << std::endl;
        exit(-1);
    }

    std::cout << "Verificando endereço de CShell..." << std::endl;
    while (!CShell_address) {
        CShell_address = get_module_base_x64(xor_a("CShell_x64.dll"));
        CFBase = get_module_base_x64(xor_a("crossfire.exe"));
        std::cout << "Aguardando por CShell_x64.dll..." << std::endl;
        Sleep(250);
    }

    std::cout << "Verificando endereço de ClientFx..." << std::endl;
    while (!Check) {
        Check = get_module_base_x64(xor_a("ClientFx_x64.fxd"));
        std::cout << "Aguardando por ClientFx_x64.fxd..." << std::endl;
        Sleep(250);
    }

    std::cout << "Inicializando menu..." << std::endl;
    InitializeMenu();

    std::cout << "Programa iniciado com sucesso!" << std::endl;

    return EXIT_SUCCESS;
}
