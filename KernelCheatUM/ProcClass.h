using namespace std;
HWND hWnd;




typedef struct _NULL_MEMORY
{
	void* buffer_address;
	UINT_PTR address;
	ULONGLONG size;
	ULONG pid;
	BOOLEAN write;
	BOOLEAN read;
	BOOLEAN req_base;
	void* output;
	const char* module_name;
	ULONG64 CShell_address;
}NULL_MEMORY;

uintptr_t CShell_address = 0;


std::uint32_t process_id = 0;
uintptr_t CFBase = 0;

//cheat pointers
uintptr_t ILTDrawPrim = NULL;
uintptr_t pPlayerClient = NULL;



D3DVIEWPORT9 viewport = { 0,0,0 };
D3DXMATRIX Projection;
D3DXMATRIX View;