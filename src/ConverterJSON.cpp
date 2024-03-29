#include <vector>
#include <string>

#include "ConverterJSON.h"

/**
* Метод получения содержимого файлов
* @return Возвращает список с содержимым файлов перечисленных
*
в config.json
*/
std::vector<std::string> ConverterJSON::GetTextDocuments() {}
/**
* Метод считывает поле max_responses для определения предельного
* количества ответов на один запрос
* @return
*/
int ConverterJSON::GetResponsesLimit() {}
/**
* Метод получения запросов из файла requests.json
* @return возвращает список запросов из файла requests.json
*/
std::vector<std::string> ConverterJSON::GetRequests() {}
/**
* Положить в файл answers.json результаты поисковых запросов
*/
void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers) {}
