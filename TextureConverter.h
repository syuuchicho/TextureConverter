#pragma once
#include<string>
#include<DirectXTex.h>

using namespace DirectX;
using namespace std;

class TextureConverter
{
public:
	/// <summary>
	///�g�p���@���o��(�\��)���� 
	/// </summary>
	static void OutputUsage();

	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�����
	/// </summary>
	/// <param name="filepath">�t�@�C���p�X</param>
	/// <param name="numOptions">�I�v�V�����̐�</param>
	/// <param name="options">�I�v�V�����z��</param>
	void ConvertTextureWICToDDS(const std::string& filepath,
		int numOptions = 0, char* options[] = nullptr);

private:
	/// <summary>
	/// �e�N�X�`���t�@�C���ǂݍ���
	/// </summary>
	/// <param name="filepath">�t�@�C���p�X</param>
	void LoadWICTextureFromFile(const std::string& filepath);

	/// <summary>
	/// �t�H���_�p�X�ƃt�@�C�����𕪗�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void SeparateFilePath(const std::wstring& filePath);

	/// <summary>
	/// DDS�e�N�X�`���Ƃ��ăt�@�C�������o��
	/// </summary>
	/// <param name="numOptions">�I�v�V�����̐�</param>
	/// <param name="options">�I�v�V�����̔z��</param>
	void SaveDDSTextureToFile(int numOptions,char*options[]);

	//�}���`�o�C�g�����񂩂烏�C�h������
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	//�摜�̏��
	DirectX::TexMetadata metadata_;
	//�摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;

	//�f�B���N�g���p�X
	std::wstring directoryPath_;
	//�t�@�C����
	std::wstring fileName_;
	//�t�@�C���g���q
	std::wstring fileExt_;
};

