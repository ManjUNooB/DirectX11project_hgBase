// ���[�U��`���b�V�� [Mesh.h]
#pragma once
#include "main.h"
#include "Camera.h"
#include "Light.h"

class CMeshMaterial {
public:
	XMFLOAT4	m_Diffuse;		// Diffuse color RGBA
	XMFLOAT4	m_Ambient;		// Ambient color RGB
	XMFLOAT4	m_Specular;		// Specular 'shininess'
	XMFLOAT4	m_Emissive;		// Emissive color RGB
	float		m_Power;		// Sharpness if specular highlight
};

class CMesh
{
private:
	ID3D11Buffer* m_pVertexBuffer;	// ���_�o�b�t�@�C���^�[�t�F�[�X�ւ̃|�C���^
	ID3D11Buffer* m_pIndexBuffer;	// �C���f�b�N�X�o�b�t�@�C���^�[�t�F�[�X�ւ̃|�C���^

	int m_nNumVertex;				// �����_��	
	int m_nNumIndex;				// ���C���f�b�N�X��

	XMFLOAT4X4 m_mWorld;
	CCamera* m_pCamera;
	CLight* m_pLight;

	CMeshMaterial m_material;		// �}�e���A��

	static ID3D11Buffer* m_pConstantBuffer[2];	// �萔�o�b�t�@
	static ID3D11SamplerState* m_pSamplerState;	// �e�N�X�`�� �T���v��
	static ID3D11VertexShader* m_pVertexShader;	// ���_�V�F�[�_
	static ID3D11InputLayout* m_pInputLayout;	// ���_�t�H�[�}�b�g
	static ID3D11PixelShader* m_pPixelShader;	// �s�N�Z���V�F�[�_

public:
	CMesh();
	virtual ~CMesh();

	static HRESULT InitShader();
	static void FinShader();

	HRESULT Init(const VERTEX_3D vertexWk[], int nVertex, const int indexWk[], int nIndex);
	virtual void Fin();
	virtual void Draw();

	void SetCamera(CCamera* pCamera) { m_pCamera = pCamera; }
	void SetLight(CLight* pLight) { m_pLight = pLight; }
	void SetWorld(XMFLOAT4X4* pWorld) { m_mWorld = *pWorld; }
	void SetMaterial(const CMeshMaterial* pMaterial);
	void GetMaterial(CMeshMaterial* pMaterial) { *pMaterial = m_material; }
	void SetDiffuse(XMFLOAT4 vDiffuse) { m_material.m_Diffuse = vDiffuse; }
};