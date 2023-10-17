#include "TextureConverter.h"

void TextureConverter::ConvertTextureWICToDDS(const std::string& filepath)
{
	//テクスチャファイルを読み込む
	LoadWICTextureFromFile(filepath);

	//②DDS形式に変換して書き出す

}

void TextureConverter::LoadWICTextureFromFile(const std::string& filepath)
{
	HRESULT result;
	//ファイルパスをワイド文字列に変換
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filepath);

	//WICテクスチャのロード
	result = LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE, &metadata_, scratchImage_);
	assert(SUCCEEDED(result));
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//ワイド文字列に変換した際の文字数を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);
	
	//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}
