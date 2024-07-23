/**
* Class for working with JSON files
*/

#ifndef CONVERTERJSON_HH
#define CONVERTERJSON_HH 1

#include <vector>
#include <string>
#include <QObject>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

class ConverterJSON : public QObject {
    Q_OBJECT

public:
    explicit ConverterJSON(QObject *parent = nullptr) : QObject(parent) {}

   /**
    * Метод получения содержимого файлов
    * @return Возвращает список с содержимым файлов, перечисленных
    * в config.json
    */
    std::vector<std::string> GetTextDocuments();
    /**
    * Метод считывает поле max_responses для определения предельного
    * количества ответов на один запрос
    * @return
    */
    int GetResponsesLimit();
    /**
    * Метод получения запросов из файла requests.json
    * @return возвращает список запросов из файла requests.json
    */
    std::vector<std::string> GetRequests();
    /**
    * Положить в файл answers.json результаты поисковых запросов
    */
    void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers);

private:
    nlohmann::json configData;
    nlohmann::json requestsData;
    const std::string configFilePath = "config.json";
    const std::string requestsFilePath = "requests.json";
    const std::string answersFilePath = "answers.json";

    bool loadConfig();
    bool loadRequests();
};

#endif // CONVERTERJSON_HH
