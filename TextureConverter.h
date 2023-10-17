#pragma once
#include<string>
#include<DirectXTex.h>

using namespace DirectX;
using namespace std;

class TextureConverter
{
public:
	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�����
	/// </summary>
	/// <param name="filepath">�t�@�C���p�X</param>
	void ConvertTextureWICToDDS(const std::string& filepath);

private:
	/// <summary>
	/// �e�N�X�`���t�@�C���ǂݍ���
	/// </summary>
	/// <param name="filepath">�t�@�C���p�X</param>
	void LoadWICTextureFromFile(const std::string& filepath);

	//�}���`�o�C�g�����񂩂烏�C�h������
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	//�摜�̏��
	DirectX::TexMetadata metadata_;
	//�摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;
};

