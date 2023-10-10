#include "TextureConverter.h"

void TextureConverter::ConvertTextureWICToDDS(const std::string& filepath)
{
	//�e�N�X�`���t�@�C����ǂݍ���
	LoadWICTextureFromFile(filepath);

	//�ADDS�`���ɕϊ����ď����o��

}

void TextureConverter::LoadWICTextureFromFile(const std::string& filepath)
{
	//�t�@�C���p�X�����C�h������ɕϊ�
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filepath);

	//�A�e�N�X�`����ǂݍ���

}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//���C�h������ɕϊ������ۂ̕��������v�Z
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);
	
	//���C�h������
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//���C�h������ɕϊ�
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}
