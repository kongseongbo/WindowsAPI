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
	Transparent, // 투명
	Black,
	Gray, //167 0 67
	White,
	End,
};

enum class eComponentType
{
	Rigidbody,
	Collider,
	Aimator,
	Sound,
	End,
};

#define _COLLIDER_LAYER 16 //16개 까지만 생성하도록
enum class eColliderLayer
{
	Default,
	//GameObject
	BackGround,
	BackGround2,
	Tile,

	Player,
	Player_Projecttile,

	Monster,
	Monster_Projecttile,

	Ground,

	//UI
	BackPack,
	UI = _COLLIDER_LAYER - 1,
	End = _COLLIDER_LAYER,
};

enum class eCameraEffect
{
	FadeIn,
	FadeOut,
	None,
};

enum class eUIType
{
	HP,
	MP,
	SHOP,
	INVENTORY,
	OPTION,


	END,
};

//불규칙적인 숫자를 이용하기 위해 사용
union ColliderID
{
	struct
	{
		UINT32 left;
		UINT32 right;
	};

	UINT64 ID;
};
typedef ColliderID TileID;

#define TILE_SIZE 32
#define TILE_SCALE 2

#define TILE_LINE_X 8
#define TILE_LINE_Y 3
