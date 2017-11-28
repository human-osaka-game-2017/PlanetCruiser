#include"PatternFactory.h"

PatternFactory::PatternFactory() {

}

PatternFactory::~PatternFactory() {

}

Pattern* PatternFactory::Create(PatternManager::PATTERN_KIND) {
	return 0;
}