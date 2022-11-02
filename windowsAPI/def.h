#pragma once

#define KEY_PREESE(KEY) k::Input::Input::GetKeyState(KEY) == k::eKeyState::PRESSED
#define KEY_DOWN(KEY) k::Input::Input::GetKeyState(KEY) == k::eKeyState::DOWN
#define KEY_UP(KEY) k::Input::Input::GetKeyState(KEY) == k::eKeyState::UP

enum class eSceneType
{
	Logo,
	Title,
	Play,
	End,
	Max,
};

enum class ePenColor
{
	Red,
	Green,
	Blue,
	End,
};

enum class eBrushColor
{
	Transparent, // ����
	Black,
	Gray, //167 0 67
	White,
	End,
};

enum class eComponentType
{
	Aimator,
	Collider,
	Sound,
	End,
};

#define _COLLIDER_LAYER 16 //16�� ������ �����ϵ���
enum class eColliderLayer
{
	Default,
	BackGround,
	Tile,

	Player,
	Player_Projecttile,

	Monster,
	Monster_Projecttile,

	BackPack,
	UI = _COLLIDER_LAYER - 1,
	End = _COLLIDER_LAYER,
};

enum class eCameraEffect
{
	None,
};

//�ұ�Ģ���� ���ڸ� �̿��ϱ� ���� ���
union ColliderID
{
	struct
	{
		UINT32 left;
		UINT32 right;
	};

	UINT64 ID;
};