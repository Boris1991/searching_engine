#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>

#include "ConverterJSON.h"


bool ConverterJSON::loadConfig() {
    std::ifstream configFile(configFilePath);
    if (!configFile.is_open()) {
        std::cerr << "Could not open file: " << configFilePath << std::endl;
        return false;
    }

    try {
        configFile >> configData;
    } catch (const std::exception& e) {
        std::cerr << "Error reading JSON: " << e.what() << std::endl;
        return false;
    }

    return true;
}

bool ConverterJSON::loadRequests() {
    std::ifstream requestsFile(requestsFilePath);
    if (!requestsFile.is_open()) {
        std::cerr << "Could not open file: " << requestsFilePath << std::endl;
        return false;
    }

    try {
        requestsFile >> requestsData;
    } catch (const std::exception& e) {
        std::cerr << "Error reading JSON: " << e.what() << std::endl;
        return false;
    }

    return true;
}





/**
* Метод получения содержимого файлов
* @return Возвращает список с содержимым файлов перечисленных
*
в config.json
*/
std::vector<std::string> ConverterJSON::GetTextDocuments() {
    if (!loadConfig()) {
        return {};
    }

    std::vector<std::string> textDocuments;
    if (configData.contains("files")) {
        for (const auto& file : configData["files"]) {
            std::ifstream textFile(file.get<std::string>());
            if (!textFile.is_open()) {
                std::cerr << "Could not open file: " << file << std::endl;
                continue;
            }

            std::string content((std::istreambuf_iterator<char>(textFile)),
                                std::istreambuf_iterator<char>());
            textDocuments.push_back(content);
        }
    }

    return textDocuments;
}
/**
* Метод считывает поле max_responses для определения предельного
* количества ответов на один запрос
* @return
*/
int ConverterJSON::GetResponsesLimit() {
    if (!loadConfig()) {
        return 0;
    }

    if (configData.contains("max_responses")) {
        return configData["max_responses"].get<int>();
    }

    return 0;
}
/**
* Метод получения запросов из файла requests.json
* @return возвращает список запросов из файла requests.json
*/
std::vector<std::string> ConverterJSON::GetRequests() {
    if (!loadRequests()) {
        return {};
    }

    std::vector<std::string> requests;
    if (requestsData.contains("requests")) {
        for (const auto& request : requestsData["requests"]) {
            requests.push_back(request.get<std::string>());
        }
    }

    return requests;
}
/**
* Положить в файл answers.json результаты поисковых запросов
*/
void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers) {
    nlohmann::json answersData;

    for (const auto& answerSet : answers) {
        nlohmann::json answerJson;
        for (const auto& answer : answerSet) {
            answerJson.push_back({{"doc_id", answer.first}, {"rank", answer.second}});
        }
        answersData.push_back(answerJson);
    }

    std::ofstream answersFile(answersFilePath);
    if (!answersFile.is_open()) {
        std::cerr << "Could not open file: " << answersFilePath << std::endl;
        return;
    }

    try {
        answersFile << answersData.dump(4);
    } catch (const std::exception& e) {
        std::cerr << "Error writing JSON: " << e.what() << std::endl;
    }
}
