#include "Light.h"

using namespace DirectX;

// �}�N����`
#define LIGHT0_DIRECTION	XMFLOAT3(0.0f, -1.0f, 1.0f)
#define LIGHT0_DIFFUSE		XMFLOAT4(0.9f, 0.9f, 0.9f, 1.0f)
#define LIGHT0_AMBIENT		XMFLOAT4(0.05f, 0.05f, 0.05f, 1.0f)
#define LIGHT0_SPECULAR		XMFLOAT4(0.2f, 0.2f, 0.2f, 1.0f)

// �R���X�g���N�^
CLight::CLight()
{
	Init();
}

// ������
void CLight::Init()
{
	XMFLOAT3 vDir = LIGHT0_DIRECTION;
	XMStoreFloat3(&m_direction, XMVector3Normalize(XMLoadFloat3(&vDir)));
	m_diffuse = LIGHT0_DIFFUSE;
	m_ambient = LIGHT0_AMBIENT;
	m_specular = LIGHT0_SPECULAR;
}