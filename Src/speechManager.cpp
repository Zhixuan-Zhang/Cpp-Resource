//
// Created by zhixuan on 4/17/22.
//


#include "../Inc/speechManager.h"


speechManager::speechManager(){
    initSpeech();
    createSpeaker();
}
speechManager::~speechManager(){

}

void speechManager::showMenu() {
    std::cout<<"********************************************"<<std::endl;
    std::cout<<"******* welcome to speech competition ******"<<std::endl;
    std::cout<<"********1. Start Competition ***************"<<std::endl;
    std::cout<<"********2. View record *********************"<<std::endl;
    std::cout<<"********3. Clean record ********************"<<std::endl;
    std::cout<<"********0. quit system *********************"<<std::endl;
    std::cout<<"********************************************"<<std::endl;
}
void speechManager::exitSystem(){
    std::cout<<"Goodbye!"<<std::endl;
    std::cin.get();
    exit(0);
}
void speechManager::initSpeech() {
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();
    this->m_Index=1;
    this->m_Record.clear();
}
void speechManager::createSpeaker(){
    std::string nameSeed = "ABCDEFGHIJKL";
    for (int i=0;i<(int)nameSeed.size();i++){
        std::string name = "Speaker";
        name+=nameSeed[i];
        Speaker sp;
        sp.setName(name);
        for (int j=0;j<2;j++){
            sp.setScore(0,j);
        }
        this->v1.push_back(i+10001);
        this->m_Speaker.insert(std::make_pair(i+10001,sp));
    }
}
void speechManager::showInfo(){
    for (auto & it : m_Speaker){
        std::cout << it.first;
        it.second.ShowInfo();
    }
}
void speechManager::startSpeech(){
    speechDraw();
    speechContest();
}
void speechManager::speechDraw(){

    if (this->m_Index==1){
        std::cout<<"First round is drawing"<<std::endl;
    }
    else{
        std::cout<<"Second round is drawing"<<std::endl;
    }
    if (m_Index==1){
        std::shuffle(v1.begin(),v1.end(), std::mt19937(std::random_device()()));
    }
    else{
        shuffle(v2.begin(),v2.end(), std::mt19937(std::random_device()()));
    }
}
void speechManager::speechContest(){

    if (m_Index==1){
        std::cout << "First round begins"<<std::endl;
    }
    else{
        std::cout << "Second round begins"<<std::endl;
    }
    std::multimap<double,int,std::greater<double>> groupScore;
    int num= 0;
    std::vector<int>v_Src;
    v_Src = m_Index==1?v1:v2;
    for (auto  it:v_Src){
        num++;
        std::deque<double>d;
        for (int i=0;i<10;i++){
            double score = (rand()%401+600)/10.f;
            d.push_back(score);
        }
        std::sort(d.begin(),d.end(),std::greater<double>());
        d.pop_back();
        d.pop_front();
        double sum = std::accumulate(d.begin(),d.end(),0.0f);
        double avg = sum/(double)d.size();
        this->m_Speaker[it].setScore(avg,m_Index-1);
        groupScore.insert(std::make_pair(avg,it));
        if (num%6==0){
            int count=0;
            for(auto & it : groupScore){
                if (count < 3) {
                    (this->m_Index == 1 ? v2 : vVictory).push_back(it.second);
                    count++;
                }
                else {
                    break;
                }
            }
            groupScore.clear();
        }
    }
    for (auto it:m_Index==1?v2:vVictory){
        std::cout<<"Name: "<<m_Speaker[it].getName()<<"  score: "<<m_Speaker[it].getScore(m_Index-1)<<std::endl;
    }
    if (m_Index==1){
        m_Index++;
    }
}

void speechManager::saveRecord(){
    std::ofstream ofs;
    ofs.open("speech.csv",std::ios::out| std::ios::app);
    for(auto it:vVictory){
        ofs<<it<<","<<m_Speaker[it].getScore(1)<<",";
    }
    ofs<<std::endl;
    ofs.close();
    std::cout<<"record saved"<<std::endl;
}

void speechManager::loadRecord(){
    std::ifstream ifs("speech.csv",std::ios::in);
    if (!ifs.is_open()){
        this->fileIsEmpty = true;
        std::cout<<"file does not exist"<<std::endl;
        ifs.close();
        return;
    }
    char ch;
    ifs>>ch;
    if (ifs.eof()){
        std::cout<<"Empty file"<<std::endl;
        fileIsEmpty = true;
        ifs.close();
        return;
    }
    fileIsEmpty = false;
    ifs.putback(ch);
    std::string data;
    std::vector<std::string> v;
    int index = 0;
    while (ifs>>data){
        int pos = -1;
        int start=0;
        while(true){
            pos = data.find(',',start);
            if(pos ==-1){
                break;
            }
            std::string temp = data.substr(start,pos-start);
            v.push_back(temp);
            start=pos+1;
        }
        this->m_Record.insert(std::make_pair(index,v));
        index++;
        v.clear();
    }
    ifs.close();
    showRecord();

}

void speechManager::showRecord(){
    for(int i=0;i<(int)this->m_Record.size();i++){
        std::cout<<m_Record[i][0]<<"    "<<m_Record[i][1]<<"    ";
        std::cout<<m_Record[i][2]<<"    "<<m_Record[i][3]<<"    ";
        std::cout<<m_Record[i][4]<<"    "<<m_Record[i][5]<<std::endl;
    }
}

void speechManager::clearRecord(){
    std::cout<<"Confirm?"<<std::endl;
    std::cout<<"1.Yes"<<std::endl;
    std::cout<<"2.No"<<std::endl;
    int selection=0;
    std::cin>>selection;
    if (selection==1){
        std::ofstream ofs("speech.csv",std::ios::trunc);
        ofs.close();
        this->initSpeech();
        this->createSpeaker();
        this->loadRecord();
        std::cout<<"CLEARED"<<std::endl;
    }
    return;
}