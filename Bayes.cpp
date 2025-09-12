/* 
Alejandro Jad
October 22, 2024
computer program using a language (C++, Python, Java, etc.) 
that implements the Bayes classifier.
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct BuysComputerData 
{
    string age;
    string income;
    string student;
    string credit_rating;
    string buys_computer;
};

struct PlayTennisData 
{
    string outlook;
    string temperature;
    string humidity;
    string windy;
    string play_tennis;
};

double calculateProbability(string featureValue, map<string, map<string, int>>& classFeatureCounts, string classValue, int totalClassCount) 
{
    if (classFeatureCounts[classValue].count(featureValue) > 0) {
        return (double) classFeatureCounts[classValue][featureValue] / totalClassCount;
    }
    return 1.0 / (totalClassCount + classFeatureCounts[classValue].size());
}

string classifyBuysComputer(vector<BuysComputerData>& trainingData, BuysComputerData& testInstance) 
{
    map<string, int> classCounts;
    map<string, map<string, int>> ageCounts, incomeCounts, studentCounts, creditRatingCounts;
    
    for (const auto& data : trainingData) {
        classCounts[data.buys_computer]++;
        ageCounts[data.buys_computer][data.age]++;
        incomeCounts[data.buys_computer][data.income]++;
        studentCounts[data.buys_computer][data.student]++;
        creditRatingCounts[data.buys_computer][data.credit_rating]++;
    }
    
    int totalYes = classCounts["yes"];
    int totalNo = classCounts["no"];

    double probYes = (double) totalYes / trainingData.size();
    probYes *= calculateProbability(testInstance.age, ageCounts, "yes", totalYes);
    probYes *= calculateProbability(testInstance.income, incomeCounts, "yes", totalYes);
    probYes *= calculateProbability(testInstance.student, studentCounts, "yes", totalYes);
    probYes *= calculateProbability(testInstance.credit_rating, creditRatingCounts, "yes", totalYes);
    
    double probNo = (double) totalNo / trainingData.size();
    probNo *= calculateProbability(testInstance.age, ageCounts, "no", totalNo);
    probNo *= calculateProbability(testInstance.income, incomeCounts, "no", totalNo);
    probNo *= calculateProbability(testInstance.student, studentCounts, "no", totalNo);
    probNo *= calculateProbability(testInstance.credit_rating, creditRatingCounts, "no", totalNo);
    

    return (probYes > probNo) ? "yes" : "no";
}

string classifyPlayTennis(vector<PlayTennisData>& trainingData, PlayTennisData& testInstance) 
{
    map<string, int> classCounts;
    map<string, map<string, int>> outlookCounts, tempCounts, humidityCounts, windyCounts;
    
    for (const auto& data : trainingData) {
        classCounts[data.play_tennis]++;
        outlookCounts[data.play_tennis][data.outlook]++;
        tempCounts[data.play_tennis][data.temperature]++;
        humidityCounts[data.play_tennis][data.humidity]++;
        windyCounts[data.play_tennis][data.windy]++;
    }
    
    int totalP = classCounts["P"];
    int totalN = classCounts["N"];
    
    double probP = (double) totalP / trainingData.size();
    probP *= calculateProbability(testInstance.outlook, outlookCounts, "P", totalP);
    probP *= calculateProbability(testInstance.temperature, tempCounts, "P", totalP);
    probP *= calculateProbability(testInstance.humidity, humidityCounts, "P", totalP);
    probP *= calculateProbability(testInstance.windy, windyCounts, "P", totalP);
    
    double probN = (double) totalN / trainingData.size();
    probN *= calculateProbability(testInstance.outlook, outlookCounts, "N", totalN);
    probN *= calculateProbability(testInstance.temperature, tempCounts, "N", totalN);
    probN *= calculateProbability(testInstance.humidity, humidityCounts, "N", totalN);
    probN *= calculateProbability(testInstance.windy, windyCounts, "N", totalN);
    
    return (probP > probN) ? "P" : "N";
}

int main() 
{
    vector<BuysComputerData> buysComputerData = {
        {"<=30", "high", "no", "fair", "no"},
        {"<=30", "high", "no", "excellent", "no"},
        {"31…40", "high", "no", "fair", "yes"},
        {">40", "medium", "no", "fair", "yes"},
        {">40", "low", "yes", "fair", "yes"},
        {">40", "low", "yes", "excellent", "no"},
        {"31…40", "low", "yes", "excellent", "yes"},
        {"<=30", "medium", "no", "fair", "no"},
        {"<=30", "low", "yes", "fair", "yes"},
        {">40", "medium", "yes", "fair", "yes"},
        {"<=30", "medium", "yes", "excellent", "yes"},
        {"31…40", "medium", "no", "excellent", "yes"},
        {"31…40", "high", "yes", "fair", "yes"},
        {">40", "medium", "no", "excellent", "no"}
    };
    
    BuysComputerData test1;
    cout << "Enter age (<=30, 31…40, >40): ";
    cin >> test1.age;
    cout << "Enter income (low, medium, high): ";
    cin >> test1.income;
    cout << "Are you a student? (yes, no): ";
    cin >> test1.student;
    cout << "Enter credit rating (fair, excellent): ";
    cin >> test1.credit_rating;
    
    string result1 = classifyBuysComputer(buysComputerData, test1);
    cout << "Prediction for 'buys_computer': " << result1 << endl;

    vector<PlayTennisData> playTennisData = {
        {"sunny", "hot", "high", "false", "N"},
        {"sunny", "hot", "high", "true", "N"},
        {"overcast", "hot", "high", "false", "P"},
        {"rain", "mild", "high", "false", "P"},
        {"rain", "cool", "normal", "false", "P"},
        {"rain", "cool", "normal", "true", "N"},
        {"overcast", "cool", "normal", "true", "P"},
        {"sunny", "mild", "high", "false", "N"},
        {"sunny", "cool", "normal", "false", "P"},
        {"rain", "mild", "normal", "false", "P"},
        {"sunny", "mild", "normal", "true", "P"},
        {"overcast", "mild", "high", "true", "P"},
        {"overcast", "hot", "normal", "false", "P"},
        {"rain", "mild", "high", "true", "N"}
    };
    
    PlayTennisData test2;
    cout << "Enter outlook (sunny, overcast, rain): ";
    cin >> test2.outlook;
    cout << "Enter temperature (hot, mild, cool): ";
    cin >> test2.temperature;
    cout << "Enter humidity (high, normal): ";
    cin >> test2.humidity;
    cout << "Is it windy? (true, false): ";
    cin >> test2.windy;

    string result2 = classifyPlayTennis(playTennisData, test2);
    cout << "Prediction for 'play_tennis': " << result2 << endl;
    
    return 0;
}
