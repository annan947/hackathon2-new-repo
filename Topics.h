#ifndef TOPICS_H
#define TOPICS_H


using namespace std;
#include <iostream>
#include <string>
#include <vector>


class topics{
    public:
        void setInfo(string info);
        void setTitle(string title);
        void setYearMade(int yearMade);
        void setImage(string filename);

        string getInfo() const;
        string getTitle() const;
        string getImage() const;
        int getYear() const;

    private:
        string info = "N/A";
        string title = "N/A";
        string imagePath = "";
        int yearMade = -1;
};


vector<topics> setTopics();


#endif