#include"PatternManager.h"
#include<string>
#include"Common.h"

PatternManager::PatternManager() {
	InitUVData();
	LoadIniFile(".\\Stage\\pattern0.ini", &m_pPatterns[PATTERN_0]);
	LoadIniFile(".\\Stage\\pattern1.ini", &m_pPatterns[PATTERN_1]);
	LoadIniFile(".\\Stage\\pattern2.ini", &m_pPatterns[PATTERN_2]);
	LoadIniFile(".\\Stage\\pattern3.ini", &m_pPatterns[PATTERN_3]);
	LoadIniFile(".\\Stage\\pattern4.ini", &m_pPatterns[PATTERN_4]);
	LoadIniFile(".\\Stage\\pattern5.ini", &m_pPatterns[PATTERN_5]);
	LoadIniFile(".\\Stage\\pattern6.ini", &m_pPatterns[PATTERN_6]);
	LoadIniFile(".\\Stage\\pattern7.ini", &m_pPatterns[PATTERN_7]);
	LoadIniFile(".\\Stage\\pattern8.ini", &m_pPatterns[PATTERN_8]);
	LoadIniFile(".\\Stage\\pattern9.ini", &m_pPatterns[PATTERN_9]);
}

PatternManager::~PatternManager() {
	for (auto mitr = m_pPatterns.begin(); mitr != m_pPatterns.end(); mitr++)
	{
		for (auto vitr = (mitr->second).begin(); vitr != (mitr->second).end(); vitr++) {
			delete *vitr;
		}
	}
}

void PatternManager::InitUVData() {
	UV tmpNormal = { 0.0f,120.0f,140.0f,140.0f, 124.0f, 124.0f };
	m_UVData["NORMAL"] = tmpNormal;
	UV tmpWide = { 140.0f,120.0f,250.0f,120.0f,234.0f,100.0f };
	m_UVData["WIDE"] = tmpWide;
	UV tmpSlender = { 390.0f,120.0f ,110.0f,220.0f,104.0f,200.0f };
	m_UVData["SLENDER"] = tmpSlender;
}

std::vector<Asteroid*>* PatternManager::LoadIniFile(const char* fileName, std::vector<Asteroid*>* pAsteroids) {
	char asteroidNumBuff[256];
	ZeroMemory(asteroidNumBuff, sizeof(asteroidNumBuff));
	GetPrivateProfileString("Header", "AsteroidNum", "", asteroidNumBuff, sizeof(asteroidNumBuff), fileName);
	int asteroidNum = std::stoi(asteroidNumBuff);

	for (int i = 1; i <= asteroidNum; ++i) {
		std::string name = "Asteroid";
		name += std::to_string(i);

		char buff[256];
		Asteroid::AsteroidIniData astData;

		ZeroMemory(buff, sizeof(buff));
		GetPrivateProfileString(name.c_str(), "X座標", "", buff, sizeof(buff), fileName);
		astData.x = std::stof(buff);

		ZeroMemory(buff, sizeof(buff));
		GetPrivateProfileString(name.c_str(), "Y座標", "", buff, sizeof(buff), fileName);
		astData.y = -(std::stof(buff) - WINDOW_HEIGHT);

		ZeroMemory(buff, sizeof(buff));
		GetPrivateProfileString(name.c_str(), "スピード", "", buff, sizeof(buff), fileName);
		astData.speed = std::stof(buff);

		ZeroMemory(buff, sizeof(buff));
		GetPrivateProfileString(name.c_str(), "拡縮率", "", buff, sizeof(buff), fileName);
		astData.magnifying = std::stof(buff);

		ZeroMemory(buff, sizeof(buff));
		GetPrivateProfileString(name.c_str(), "種類", "", buff, sizeof(buff), fileName);
		astData.tlTu = m_UVData[std::string(buff)].tu;
		astData.tlTv = m_UVData[std::string(buff)].tv;
		astData.width = m_UVData[std::string(buff)].width;
		astData.height = m_UVData[std::string(buff)].height;
		astData.collidedWidth = m_UVData[std::string(buff)].collidedWidth;
		astData.collidedHeight = m_UVData[std::string(buff)].collidedHeight;

		pAsteroids->push_back(new Asteroid(astData));
	}

	return pAsteroids;
}

const std::vector<Asteroid*>& PatternManager::GetPatternInfo(PATTERN_KIND kind) {
	return m_pPatterns[kind];
}