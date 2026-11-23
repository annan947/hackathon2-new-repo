#include "Topics.h"
#include <iostream>
//#include <string>



void topics::setInfo(string topicInfo){
    info = topicInfo;
}

void topics::setTitle(string topicTitle){
    title = topicTitle;
}

void topics::setYearMade(int topicYear){
    yearMade = topicYear;
}

void topics::setImage(string filename){
    imagePath = filename;
}

string topics::getTitle() const{
    return title;
}

string topics::getImage() const{
    return imagePath;
}

string topics::getInfo() const{
    return info;
}

int topics::getYear() const{
    return yearMade;
}

// this isnt apart of the class function definition, this is independent to making each object for the class
vector<topics> setTopics(){

    vector<topics> allTopics;

    topics Tetris;
    topics Atari;
    topics Space_Invaders;
    topics Magnavox_Odyssey;
    topics Atari_Pong;
    topics First_Gaming_Consoles;
    topics SpaceWars;
    topics Tennis_For_Two;
    topics OXO;
    topics Spasim;
    topics ArcadeGame;
    topics MainFrameComputerGames;

    Tetris.setInfo("A puzzle game developed in the Soviet Union where players arrange falling blocks of different shapes to complete horizontal lines. Completed lines disappear, giving the player more space to continue playing. Tetris became one of the most recognizable puzzle games in video game history.");
    Atari.setInfo("A home video game console that used interchangeable cartridges, allowing players to buy and play different games on the same system. It used joysticks and could display games in color. The Atari 2600 helped make video game consoles popular in households.");
    Magnavox_Odyssey.setInfo("The first commercial home video game console. It connected to a television and allowed players to play simple games such as table tennis. Unlike modern consoles, it did not have sound or advanced graphics, and some games used plastic overlays placed on the television screen.");
    Space_Invaders.setInfo("An arcade shooting game where players control a laser cannon and defend themselves against waves of descending aliens. The aliens gradually move faster as the player eliminates them. Space Invaders became extremely popular and helped start the golden age of arcade video games.");
    Atari_Pong.setInfo("A simple arcade game based on table tennis, where two players control paddles to bounce a ball back and forth. Players score points when their opponent misses the ball. Pong became one of the first commercially successful video games and helped popularize arcade gaming.");
    First_Gaming_Consoles.setInfo("Electronic devices designed primarily for playing video games, usually connected to a television or equipped with their own screen. Early consoles had simple built-in games, while later systems introduced interchangeable cartridges. Consoles helped bring video games from laboratories and arcades into people's homes.");
    SpaceWars.setInfo("Developed at MIT in 1962, Spacewar! was an early computer game in which two players controlled spaceships battling around a star. Its gameplay influenced later video games and arcade designs.");
    Tennis_For_Two.setInfo("A two-player tennis game displayed on an oscilloscope, a device normally used to measure electrical signals. Players used controllers to hit a ball back and forth over a net. It was one of the first video games designed purely for entertainment rather than research.");
    OXO.setInfo("Players input their movement using a rotary telephone, choosing which tile to play in a tic-tac-toe match. The computer then makes its move. This was one of the earliest examples of a computer playing against a human, using basic artificial intelligence.");
    Spasim.setInfo("One of the earliest 3D multiplayer computer games. Players controlled spaceships and explored a virtual space environment while interacting with other players. The game supported up to 32 players connected through the PLATO computer network, making it an early example of online multiplayer gaming.");
    ArcadeGame.setInfo("Video games played on machines typically found in arcades, restaurants, and other public locations. Players usually inserted coins to play and competed to achieve high scores. Games like Pong and Space Invaders helped make arcades extremely popular during the 1970s and 1980s.");
    MainFrameComputerGames.setInfo("Early video games developed on large, expensive computers primarily used by universities and research institutions. These computers were not originally designed for gaming, but programmers experimented with creating interactive games. Games like OXO and Spacewar! helped introduce concepts that would influence future video games.");


    
    Tetris.setYearMade(1984);
    Atari.setYearMade(1977);
    Magnavox_Odyssey.setYearMade(1972);
    Space_Invaders.setYearMade(1978);
    Atari_Pong.setYearMade(1972);
    First_Gaming_Consoles.setYearMade(1972);
    SpaceWars.setYearMade(1962);
    Tennis_For_Two.setYearMade(1958);
    OXO.setYearMade(1952);
    Spasim.setYearMade(1974);

    Tetris.setTitle("Tetris");
    Atari.setTitle("Atari");
    Magnavox_Odyssey.setTitle("Magnavox_Odyssey");
    Space_Invaders.setTitle("Space_Invaders");
    Atari_Pong.setTitle("Atari_Pong");
    First_Gaming_Consoles.setTitle("First Gaming Consoles");
    SpaceWars.setTitle("SpaceWars!");
    Tennis_For_Two.setTitle("Tennis For Two");
    OXO.setTitle("OXO");
    Spasim.setTitle("Spasim");
    ArcadeGame.setTitle("Arcade Games");
    MainFrameComputerGames.setTitle("MainFrame Computer Games");


    // New image paths for popup windows (one image for each topic).
    Tetris.setImage("images/tetris.png");
    Atari.setImage("images/atari2600.png");
    Space_Invaders.setImage("images/spaceinvaders.png");
    Magnavox_Odyssey.setImage("images/odyssey.png");
    Atari_Pong.setImage("images/pong.png");
    First_Gaming_Consoles.setImage("images/consoles.png");
    SpaceWars.setImage("images/spacewar.png");
    Tennis_For_Two.setImage("images/tennis.png");
    OXO.setImage("images/oxo.png");
    Spasim.setImage("images/spasim.png");
    ArcadeGame.setImage("images/arcade.png");
    MainFrameComputerGames.setImage("images/mainframe.png");

    allTopics.push_back(Tetris); //index 0
    allTopics.push_back(Atari); //index 1
    allTopics.push_back(Space_Invaders); // index 2
    allTopics.push_back(Magnavox_Odyssey); // so on
    allTopics.push_back(Atari_Pong);
    allTopics.push_back(First_Gaming_Consoles);
    allTopics.push_back(SpaceWars);
    allTopics.push_back(Tennis_For_Two);
    allTopics.push_back(OXO);
    allTopics.push_back(Spasim);
    allTopics.push_back(ArcadeGame);
    allTopics.push_back(MainFrameComputerGames);
    
    
    
    return allTopics;



    

}
 



