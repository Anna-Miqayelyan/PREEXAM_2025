#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Subscriber{
    public:
    virtual void notify(string videoTitle)=0;
};
class Channel{
    public:
    virtual void subscribe(Subscriber* s)=0;
    virtual void unsubscribe(Subscriber* s)=0;
    virtual void uploadVideo(string title)=0;

};
class YouTubeChannel: public Channel{
    public:
vector<Subscriber*> subscribers;
string channelName;
YouTubeChannel(string name){
    channelName=name;
}
void subscribe(Subscriber* s) override{
    subscribers.push_back(s);

}
void unsubscribe(Subscriber* s)override{
            subscribers.erase(remove(subscribers.begin(), subscribers.end(), s), subscribers.end());

}
void uploadVideo(string title) override{
    cout<<"New video: "<<title<<endl;
    for(Subscriber* s:subscribers)
{
    s->notify(title);
}}
};
class User: public Subscriber{
public:
string username;
User(string name){
username=name;
}
void notify(string videoTitle)override{
    cout<<username<<", new video uploaded: "<< videoTitle<<endl;
}
};
int main(){
 YouTubeChannel* channel = new YouTubeChannel("OpenAI Dev");

    User* anna = new User("Anna");
    User* david = new User("David");

    channel->subscribe(anna);
    channel->subscribe(david);

    channel->uploadVideo("Observer Pattern Explained");
    channel->uploadVideo("C++ Smart Pointers Guide");

    delete anna;
    delete david;
    delete channel;

    return 0;

}