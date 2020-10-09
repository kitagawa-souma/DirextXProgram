#include <Windows.h>

// �E�B���h�E�v���V�[�W���̍쐬
LRESULT CALLBACK WindowProcedure(HWND window_handle, UINT message_id, WPARAM wparam, LPARAM lparam) {
	return DefWindowProc(window_handle, message_id, wparam, lparam);
}

// ���C���֐�
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmpLine, INT nCmdShow) {

	// �E�B���h�E������
	WNDCLASSA window_class = {
		CS_HREDRAW | CS_VREDRAW,
		WindowProcedure,
		0,
		0,
		hInstance,
		LoadIcon(nullptr, IDI_APPLICATION),
		LoadCursor(nullptr, IDC_ARROW),
		nullptr,
		nullptr,
		"WindowClass",
	};

	// �E�B���h�E�o�^
	if (RegisterClassA(&window_class) == 0) {
		return 0;
	}

	int width = 640;
	int height = 480;
	// �E�B���h�E�쐬
	HWND window_handle = CreateWindowA(
		"WindowClass",
		"�E�B���h�E�쐬�ۑ�",
		(WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME),
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		width,
		height,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	// �E�B���h�E�̕\��
	ShowWindow(window_handle, SW_SHOW);

	// ���C�����[�v
	while (true) {
		MSG message;
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else {
			// �Q�[������
		}
	}
}