#include <irrlicht.h>


using namespace irr;

/*
* �Ʒ� ���ӽ����̽��鿡 ���� ������ �Ʒ� �Ŵ��� ����
* http://irrlicht.sourceforge.net/docu/namespaces.html
*/
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

/*
* pragma comment �� ��Ŀ �ɼ�
* https://docs.microsoft.com/ko-kr/cpp/build/reference/linker-options?view=msvc-160
* subsystem:windows �� console�̳� �� ����
* ENTRY: 
* mainCRTStartup�� �����ϸ� main() �Լ��� ���������� ���
* WinMainCRTStartup�� �����ϸ�WinMain() �Լ��� ���������� ���, ��, �̰��, �������� �ü�� �ܿ��� ��� ����.
* 
*/

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif


int main()
{
	// ����̽� ����: ���� �⺻�� �Ǵ� �ϸ���Ʈ�� ����
	// deviceType : ����Ʈ���� ������, DirectX, OpenGL �� ����
	// windowSize : â ũ��
	// bits : �ȼ��� �÷� ����, ����� 16��Ʈ �÷� (����Ʈ�� 16)
	// fullscreen :  â���
	// stencilbuffer : �׸��� ���� �׸��� ���� ���ٽǹ��� ��� ����
	// vsync : vsynce enabled, true of false, Ǯ��ũ���϶��� �ǹ̸� ����
	// eventReciver : �̺�Ʈ ���� ��ü ����, ������� �������� 0

	E_DRIVER_TYPE driverType = EDT_OPENGL;
	IrrlichtDevice* device =
		createDevice(driverType, dimension2d<u32>(640, 480), 16,
			false, false, false, 0);

	if (!device)
		return 1;

	// ���ø����̼� â ���� ����, L �� wide character strings�� �ǹ�(�����ڵ� ���� ��Ƽ����Ʈ ��Ʈ��)
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

	// ���� ����, ���� ����̹�, ���Ŵ���, GUIȯ�濡 ���� �����͸� �̸� �޾Ƴ���
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	device->getFileSystem()->addFileArchive("../../media/map-20kdm2.pk3");

	
	// ������ ���������� .pk3 ��ī�̺� ������ �ϸ���Ʈ�� ���Ͻý��ۿ� �߰�
	// �׷���, �� �ȿ� ����ִ� ���ҽ����� ����� �� �ֵ�.

	// �׽�Ʈ �� �ؽ�Ʈ ���  (GUI)
	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
		rect<s32>(10, 10, 260, 22), true);

	// �׽�Ʈ �� �� ��� (����ũ2 ��)
	//IAnimatedMesh* mesh = smgr->getMesh("../../media/sydney.md2");
	IAnimatedMesh* mesh = smgr->getMesh("../../media/chrm_mike.obj.md2");
	if (!mesh)
	{
		device->drop();
		return 1;
	}
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);

	
	// ���͸��� ����, ������ ������ �ϴ� ������(������ ����(dynamic light)�� ���� ������ �ѳ����� ���� ���������� ����)
	// �ִϸ��̼� - STAND
	// ����������, �ؽ��� ����
	if (node)
	{
		core::vector3df scale(75.0f, 75.0f, 75.0f);
		node->setScale(scale);

		node->setMaterialFlag(EMF_LIGHTING, false);
		//node->setMD2Animation(scene::EMAT_STAND);
		bool animRet = node->setMD2Animation("Walk");
		//node->setMaterialTexture(0, driver->getTexture("../../media/sydney.bmp"));
		node->setMaterialTexture(0, driver->getTexture("../../media/chrm_mike.png"));
	}

	// ī�޶� ����
	// parent : 0�̸� parent ����
	// position : ī�޸� ��ġ
	// target : �ٶ󺸴� ��ġ(���� ��ġ)
	smgr->addCameraSceneNode(0, vector3df(0, 130, -140), vector3df(0, 5, 0));

	
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