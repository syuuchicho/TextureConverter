#pragma once
#include<string>
#include<DirectXTex.h>

using namespace DirectX;
using namespace std;

class TextureConverter
{
public:
	/// <summary>
	/// テクスチャをWICからDDSに変換する
	/// </summary>
	/// <param name="filepath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filepath);

private:
	/// <summary>
	/// テクスチャファイル読み込み
	/// </summary>
	/// <param name="filepath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filepath);

	//マルチバイト文字列からワイド文字列
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	//画像の情報
	DirectX::TexMetadata metadata_;
	//画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;
};

