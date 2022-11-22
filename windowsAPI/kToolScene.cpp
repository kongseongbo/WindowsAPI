#include "framework.h"
#include "WindowsAPI.h"
#include "kToolScene.h"
#include "kApplication.h"
#include "kSceneManager.h"
#include "kScene.h"
#include "kTilePalette.h"
#include "kImage.h"
#include "kInput.h"


namespace k
{

    ToolScene::ToolScene()
        : mTileIndex(0)
    {
        mTilePalette = new TilePalette();
    }

    ToolScene::~ToolScene()
    {
        delete mTilePalette;
    }

    void ToolScene::Initialize()
    {
    }

    void ToolScene::Tick()
    {
        if (mTilePalette)
            mTilePalette->Tick();
    }

    void ToolScene::Render(HDC hdc)
    {
        Scene::Render(hdc);

        WindowData mainWidnow = Application::GetInstance().GetWindowData();

        HPEN redPen = CreatePen(PS_SOLID, 2, RGB(0, 125, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

        int maxRow = mainWidnow.height / TILE_SIZE * TILE_SCALE + 1;
        for (size_t i = 0; i < maxRow; i++)
        {
            MoveToEx(hdc, 0, TILE_SIZE * i * TILE_SCALE, nullptr);
            LineTo(hdc, mainWidnow.width, TILE_SIZE * i * TILE_SCALE);
        }

        int maxColumn = mainWidnow.width / TILE_SIZE * TILE_SCALE + 1;
        for (size_t i = 0; i < maxColumn; i++)
        {
            MoveToEx(hdc, TILE_SIZE * i * TILE_SCALE, 0, nullptr);
            LineTo(hdc, TILE_SIZE * i * TILE_SCALE, mainWidnow.height);
        }

        (HPEN)SelectObject(hdc, oldPen);
        DeleteObject(redPen);
    }

    void ToolScene::Enter()
    {
        Application::GetInstance().SetMenuBar(true);
    }

    void ToolScene::Exit()
    {
    }
}

LRESULT CALLBACK AtlasWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        WindowData windowData
            = k::Application::GetInstance().GetWindowData();

        WindowData atlasWindowData
            = k::Application::GetInstance().GetAtlasWindowData();

        k::Scene* scene = k::SceneManager::GetPlayScene();
        k::ToolScene* toolScene = dynamic_cast<k::ToolScene*>(scene);

        k::Image* atlas = toolScene->GetAtalasImage();

        RECT rect = { 0, 0, atlas->GetWidth() * TILE_SCALE, atlas->GetHeight() * TILE_SCALE };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
        // 윈도우 크기 변경
        SetWindowPos(hWnd,
            nullptr, windowData.width, 0
            , rect.right - rect.left
            , rect.bottom - rect.top
            , 0
        );

        ShowWindow(hWnd, true);
        UpdateWindow(hWnd);

    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
            //case IDM_ABOUT:
            //    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            //    break;
            //case IDM_EXIT:
            //    DestroyWindow(hWnd);
            //    break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_LBUTTONDOWN:
    {
        if (GetFocus())
        {
            k::Vector2  mousePos = k::Input::GetMousePos(hWnd);

            int y = mousePos.y / (TILE_SIZE * TILE_SCALE);
            int x = mousePos.x / (TILE_SIZE * TILE_SCALE);

            int index = (y * TILE_LINE_X) + (x % TILE_LINE_X);
            k::Scene* scene = k::SceneManager::GetPlayScene();
            k::ToolScene* toolScene = dynamic_cast<k::ToolScene*>(scene);
            toolScene->SetTileIndex(index);
        }
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        WindowData atlasWindowData
            = k::Application::GetInstance().GetAtlasWindowData();

        k::Scene* scene = k::SceneManager::GetPlayScene();
        k::ToolScene* toolScene = dynamic_cast<k::ToolScene*>(scene);

        k::Image* atlas = toolScene->GetAtalasImage();
        k::Vector2 pos(k::Vector2::Zero);

        TransparentBlt(hdc, pos.x, pos.y
            , atlas->GetWidth() * TILE_SCALE, atlas->GetHeight() * TILE_SCALE
            , atlas->GetDC(), 0, 0, atlas->GetWidth(), atlas->GetHeight()
            , RGB(255, 0, 255));

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_DESTROY:
    {
        PostQuitMessage(0);
        //KillTimer(hWnd, 0);
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}