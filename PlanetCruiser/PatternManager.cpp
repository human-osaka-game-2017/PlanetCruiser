#include"PatternManager.h"
#include<string>

PatternManager::PatternManager() {
	InitUVData();
	LoadIniFile(".\\Assets\\pattern0.ini", &m_pPatterns[PATTERN_0]);
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
	UV normal = { 0.0f,0.0f };
	m_UVData["NORMAL"] = normal;
}

std::vector<Asteroid*>* PatternManager::LoadIniFile(const char* fileName, std::vector<Asteroid*>* asteroids) {
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
		astData.y = std::stof(buff);

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

		asteroids->push_back(new Asteroid(astData));
	}

	return asteroids;
}

const std::vector<Asteroid*>& PatternManager::GetPatternInfo(PATTERN_KIND kind) {
	return m_pPatterns[kind];
}