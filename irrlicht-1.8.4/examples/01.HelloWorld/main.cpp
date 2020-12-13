#include <irrlicht.h>


using namespace irr;

/*
* 아래 네임스페이스들에 대한 설명은 아래 매뉴얼 참조
* http://irrlicht.sourceforge.net/docu/namespaces.html
*/
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

/*
* pragma comment 중 링커 옵션
* https://docs.microsoft.com/ko-kr/cpp/build/reference/linker-options?view=msvc-160
* subsystem:windows 냐 console이냐 등 선택
* ENTRY: 
* mainCRTStartup을 지정하면 main() 함수를 진입점으로 사용
* WinMainCRTStartup로 지정하면WinMain() 함수를 진입점으로 사용, 단, 이경우, 윈도우즈 운영체제 외에는 사용 못함.
* 
*/

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif


int main()
{
	// 디바이스 생성: 가장 기본이 되는 일리히트의 설정
	// deviceType : 소프트웨어 렌더러, DirectX, OpenGL 중 선택
	// windowSize : 창 크기
	// bits : 픽셀당 컬러 지정, 현재는 16비트 컬러
	// fullscreen :  창모드
	// stencilbuffer : 그림자 등을 그리기 위한 스텐실버퍼 사용 여부
	// vsync : vsynce enabled, true of false, 풀스크린일때만 의미를 가짐
	// eventReciver : 이벤트 받을 객체 지정, 사용하지 않으려면 0
	IrrlichtDevice* device =
		createDevice(video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
			false, false, false, 0);

	if (!device)
		return 1;

	// 어플리케이션 창 제목 설정, L 은 wide character strings을 의미(유니코드 같은 멀티바이트 스트링)
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	// 자주 사용될, 비디오 드라이버, 씬매니저, GUI환경에 대한 포인터를 미리 받아놓기
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	
	// 테스트 용 텍스트 출력  (GUI)
	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
		rect<s32>(10, 10, 260, 22), true);

	// 테스트 용 모델 출력 (퀘이크2 모델)
	//IAnimatedMesh* mesh = smgr->getMesh("../../media/sydney.md2");
	IAnimatedMesh* mesh = smgr->getMesh("../../media/jesus_forMD2.blend.md2");
	if (!mesh)
	{
		device->drop();
		return 1;
	}
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);

	
	// 머터리얼 설정, 라이팅 설정은 일단 꺼놓음(아직은 조명(dynamic light)이 없기 때문에 켜놓으면 모델이 검정색으로 나옴)
	// 애니메이션 - STAND
	// 마지막으로, 텍스쳐 설정
	if (node)
	{
		node->setMaterialFlag(EMF_LIGHTING, false);
		//node->setMD2Animation(scene::EMAT_STAND);
		bool animRet = node->setMD2Animation("fram");
		//node->setMaterialTexture(0, driver->getTexture("../../media/sydney.bmp"));
		node->setMaterialTexture(0, driver->getTexture("../../media/jesus.png"));
	}

	// 카메라 설정
	// parent : 0이면 parent 없음
	// position : 카메리 위치
	// target : 바라보는 위치(모델의 위치)
	smgr->addCameraSceneNode(0, vector3df(0, 10, -15), vector3df(0, 5, 0));

	
	while (device->run())
	{
		
		driver->beginScene(true, true, SColor(255, 100, 101, 140));

		smgr->drawAll();
		guienv->drawAll();

		driver->endScene();
	}

	
	device->drop();

	return 0;
}