//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <iostream>
//#include<fstream>
//#include <conio.h>
//const int gridSize = 65;
//using namespace sf;
//using namespace std;
//char input();
//void puzzle(char arr[9][9]);
//bool emp(char arr[9][9]);
//bool checkRow(char arr[9][9], char ch, int r, int c);
//bool checkCol(char arr[9][9], char ch, int r, int c);
//bool checkBox(char arr[9][9], char ch, int r, int c);
//void store(char arr[9][9], char ch, int r, int c);
//bool checkSudoku(char arr[9][9]);
//int main()
//{
//    int r, c;
//    //fonts types
//    Font font, font1;
//    font.loadFromFile("Fonts/Rambutan Days.ttf");
//    font1.loadFromFile("Fonts/BebasNeue-Regular.ttf");
//    //strings to write on windows
//    string rules = "GAME RULES", error = "Invalid Input", err = "The number you have entered\nalready exists in either row,\ncolumn or grid", contText = "Continue Game", contText1 = " Would you like to contue previous Game?\nPress C to continue\nPress N to start new game", gameFin = "Game Finished";
//    string rule = "1) Sudoku grid consists of 9x9 spaces.\n2) You can use only numbers from 0 to 9.\n3) Each 3X3 block can only contain numbers from\n    1 to 9.\n4) Each vertical column can only contain numbers\n     from 1 to 9.\n5) Each horizontal row can only contain numbers \n     from 1 to 9.\n6) Use 0 to delete a number\n7) Press S to save the game";
//    //some variables for game
//    char ch, arr[9][9], num;
//    bool sudokuSolved = false;
//    //graphics texts 
//    Text rules1, rules2, fin, cont, cont1, text1, text, text2, saveT, saveTx, erTxt;
//    //rules text
//    rules1.setFont(font); rules1.setCharacterSize(50); rules1.setFillColor(Color::Black); rules1.setStyle(Text::Bold); rules1.setString(rules); rules1.setPosition(195, 15);
//    rules2.setFont(font1); rules2.setCharacterSize(35); rules2.setFillColor(Color::Black); rules2.setStyle(Text::Bold); rules2.setString(rule); rules2.setPosition(10, 80);
//    //continue game text
//    cont.setFont(font); cont.setCharacterSize(45); cont.setFillColor(Color::Black); cont.setStyle(Text::Bold); cont.setString(contText); cont.setPosition(115, 15);
//    cont1.setFont(font1); cont1.setCharacterSize(35); cont1.setFillColor(Color::Black); cont1.setStyle(Text::Bold); cont1.setString(contText1); cont1.setPosition(10, 80);
//    //window asking user to continue previous game
//    sf::RenderWindow con(sf::VideoMode(550, 230), "Continue Game", sf::Style::Titlebar | sf::Style::Close);
//    {
//        while (con.isOpen())
//        {
//            sf::Event event2;
//            while (con.pollEvent(event2))
//            {
//                switch (event2.type)
//                {
//                case sf::Event::Closed:
//                    con.close();
//                    break;
//                }
//            }
//            con.clear(sf::Color(64, 130, 109));
//            con.draw(cont);
//            con.draw(cont1);
//            //if player wants to continue the game C is pressed
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
//            {
//                //loading previous game that was saved 
//                ifstream sud;
//                sud.open("sudoku game.txt");
//                if (!sud)
//                {
//                    cout << "Error";
//                }
//                else
//                {
//                    for (int i = 0; i < 9; i++)
//                    {
//                        for (int j = 0; j < 9; j++)
//                        {
//                            //copying each number from file
//                            sud >> num;
//                            if (num == 0)
//                            {
//                                //if number stored is zero then store it as space in array
//                                arr[i][j] = ' ';
//                            }
//                            else
//                            {
//                                //else store the number as it is
//                                arr[i][j] = num;
//                            }
//                        }
//                    }
//                }
//                con.close();
//            }
//            //if player does not want to continue the game N is pressed
//            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
//            {
//                //new random puzzle is generated
//                puzzle(arr);
//                //game rules are shown on new window
//                sf::RenderWindow gamerules(sf::VideoMode(700, 500), "Game Rules", sf::Style::Titlebar | sf::Style::Close);
//                while (gamerules.isOpen())
//                {
//                    sf::Event event2;
//                    while (gamerules.pollEvent(event2))
//                    {
//                        switch (event2.type)
//                        {
//                        case sf::Event::Closed:
//                            gamerules.close();
//                            break;
//                        case sf::Event::MouseButtonPressed:
//                            gamerules.close();
//                            break;
//                        }
//                    }
//                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//                    {
//                        gamerules.close();
//                    }
//                    //rules are displayed
//                    gamerules.clear(sf::Color(64, 130, 109));
//                    gamerules.draw(rules1);
//                    gamerules.draw(rules2);
//                    gamerules.display();
//                }
//                con.close();
//            }
//            con.display();
//        }
//    }
//    //Main window containing the game board
//    sf::RenderWindow window(sf::VideoMode(850, 750), "SUDOKU", sf::Style::Titlebar | sf::Style::Close);
//    ////GRID
//    //inner vertical lines
//    sf::RectangleShape vertical(sf::Vector2f(3, 585)); vertical.setFillColor(sf::Color::Black);
//
//    //inner horizontal lines 
//    sf::RectangleShape horizontal(sf::Vector2f(585, 3)); horizontal.setFillColor(sf::Color::Black);
//
//    //outer grid
//    sf::RectangleShape grid1(sf::Vector2f(190, 190)); grid1.setFillColor(sf::Color(99, 137, 106)); grid1.setOutlineThickness(5.5f);
//    grid1.setOutlineColor(sf::Color::Black);
//
//    //winning text
//    text1.setFont(font1); text1.setCharacterSize(35); text1.setFillColor(Color::Black); text1.setStyle(Text::Bold); text1.setString("     CONGRATULATIONS\nYOU HAVE WON THE GAME!"); text1.setPosition(30, 70);
//    fin.setFont(font); fin.setCharacterSize(40); fin.setFillColor(Color::Black); fin.setStyle(Text::Bold); fin.setString(gameFin); fin.setPosition(40, 15);
//
//    //text sudoku
//    text.setFont(font); text.setCharacterSize(50); text.setFillColor(Color::Black); text.setStyle(Text::Bold); text.setString("SUDOKU"); text.setPosition(330, 0);
//
//    //text error
//    text2.setFont(font); text2.setCharacterSize(35); text2.setFillColor(Color::Black); text2.setStyle(Text::Bold); text2.setString(error); text2.setPosition(60, 5);
//    erTxt.setFont(font1); erTxt.setCharacterSize(30); erTxt.setFillColor(Color::Black); erTxt.setStyle(Text::Bold); erTxt.setString(err); erTxt.setPosition(10, 50);
//
//    //game saving text
//    saveT.setFont(font); saveT.setCharacterSize(35); saveT.setFillColor(Color::Black); saveT.setStyle(Text::Bold); saveT.setString("Would you like to\n save the game?"); saveT.setPosition(60, 10);
//    saveTx.setFont(font); saveTx.setCharacterSize(25); saveTx.setFillColor(Color::Black); saveTx.setStyle(Text::Bold); saveTx.setString("Press Y for yes\nPress N for no"); saveTx.setPosition(30, 120);
//
//    //GAME INPUT NUMBER TEXTS
//    // 
//    //1st line
//    Text n11, n12, n13, n14, n15, n16, n17, n18, n19;
//    n11.setFont(font); n11.setCharacterSize(50); n11.setFillColor(Color::Black); n11.setStyle(Text::Bold); num = arr[0][0]; n11.setString(num);
//    n12.setFont(font); n12.setCharacterSize(50); n12.setFillColor(Color::Black); n12.setStyle(Text::Bold); num = arr[0][1]; n12.setString(num);
//    n13.setFont(font); n13.setCharacterSize(50); n13.setFillColor(Color::Black); n13.setStyle(Text::Bold); n13.setOrigin(10.f, 10.f); num = arr[0][2]; n13.setString(num);
//    n15.setFont(font); n15.setCharacterSize(50); n15.setFillColor(Color::Black); n15.setStyle(Text::Bold); n15.setOrigin(10.f, 10.f); num = arr[0][4]; n15.setString(num);
//    n17.setFont(font); n17.setCharacterSize(50); n17.setFillColor(Color::Black); n17.setStyle(Text::Bold); n17.setOrigin(10.f, 10.f); num = arr[0][6]; n17.setString(num);
//    n18.setFont(font); n18.setCharacterSize(50); n18.setFillColor(Color::Black); n18.setStyle(Text::Bold); n18.setOrigin(10.f, 10.f); num = arr[0][7]; n18.setString(num);
//    n14.setFont(font); n14.setCharacterSize(50); n14.setFillColor(Color(13, 43, 32)); n14.setStyle(Text::Bold); num = arr[0][3]; n14.setString(num); n14.setPosition(340, 70);
//    n16.setFont(font); n16.setCharacterSize(50); n16.setFillColor(Color(13, 43, 32)); n16.setStyle(Text::Bold); n16.setOrigin(10.f, 10.f); num = arr[0][5]; n16.setString(num); n16.setPosition(485, 80);
//    n19.setFont(font); n19.setCharacterSize(50); n19.setFillColor(Color(13, 43, 32)); n19.setStyle(Text::Bold); n19.setOrigin(10.f, 10.f); num = arr[0][8]; n19.setString(num); n19.setPosition(670, 80);
//
//    //2nd line
//    Text n21, n22, n23, n24, n25, n26, n27, n28, n29;
//    n21.setFont(font); n21.setCharacterSize(50); n21.setFillColor(Color::Black); n21.setStyle(Text::Bold); n21.setOrigin(10.f, 10.f); num = arr[1][0]; n21.setString(num);
//    n22.setFont(font); n22.setCharacterSize(50); n22.setFillColor(Color(13, 43, 32)); n22.setStyle(Text::Bold); n22.setOrigin(10.f, 10.f); num = arr[1][1]; n22.setString(num); n22.setPosition(227, 145);
//    n23.setFont(font); n23.setCharacterSize(50); n23.setFillColor(Color::Black); n23.setStyle(Text::Bold); n23.setOrigin(10.f, 10.f); num = arr[1][2]; n23.setString(num);
//    n24.setFont(font); n24.setCharacterSize(50); n24.setFillColor(Color::Black); n24.setStyle(Text::Bold); n24.setOrigin(10.f, 10.f); num = arr[1][3]; n24.setString(num);
//    n25.setFont(font); n25.setCharacterSize(50); n25.setFillColor(Color::Black); n25.setStyle(Text::Bold); n25.setOrigin(10.f, 10.f); num = arr[1][4]; n25.setString(num);
//    n26.setFont(font); n26.setCharacterSize(50); n26.setFillColor(Color::Black); n26.setStyle(Text::Bold); n26.setOrigin(10.f, 10.f); num = arr[1][5]; n26.setString(num);
//    n27.setFont(font); n27.setCharacterSize(50); n27.setFillColor(Color(13, 43, 32)); n27.setStyle(Text::Bold); n27.setOrigin(10.f, 10.f); num = arr[1][6]; n27.setString(num);
//    n28.setFont(font); n28.setCharacterSize(50); n28.setFillColor(Color::Black); n28.setStyle(Text::Bold); n28.setOrigin(10.f, 10.f); num = arr[1][7]; n28.setString(num);
//    n29.setFont(font); n29.setCharacterSize(50); n29.setFillColor(Color::Black); n29.setStyle(Text::Bold); n29.setOrigin(10.f, 10.f); num = arr[1][8]; n29.setString(num);
//
//    //3rd line
//    Text n31, n32, n33, n34, n35, n36, n37, n38, n39;
//    n36.setFont(font); n36.setCharacterSize(50); n36.setFillColor(Color(13, 43, 32)); n36.setStyle(Text::Bold); n36.setOrigin(10.f, 10.f); num = arr[2][5]; n36.setString(num); n36.setPosition(487, 210);
//    n38.setFont(font); n38.setCharacterSize(50); n38.setFillColor(Color(13, 43, 32)); n38.setStyle(Text::Bold); n38.setOrigin(10.f, 10.f); num = arr[2][7]; n38.setString(num); n38.setPosition(610, 210);
//    n31.setFont(font); n31.setCharacterSize(50); n31.setFillColor(Color::Black); n31.setStyle(Text::Bold); n31.setOrigin(10.f, 10.f); num = arr[2][0]; n31.setString(num);
//    n32.setFont(font); n32.setCharacterSize(50); n32.setFillColor(Color::Black); n32.setStyle(Text::Bold); n32.setOrigin(10.f, 10.f); num = arr[2][1]; n32.setString(num);
//    n33.setFont(font); n33.setCharacterSize(50); n33.setFillColor(Color(13, 43, 32)); n33.setStyle(Text::Bold); n33.setOrigin(10.f, 10.f); num = arr[2][2]; n33.setString(num);
//    n34.setFont(font); n34.setCharacterSize(50); n34.setFillColor(Color::Black); n34.setStyle(Text::Bold); n34.setOrigin(10.f, 10.f); num = arr[2][3]; n34.setString(num);
//    n35.setFont(font); n35.setCharacterSize(50); n35.setFillColor(Color::Black); n35.setStyle(Text::Bold); n35.setOrigin(10.f, 10.f); num = arr[2][4]; n35.setString(num);
//    n37.setFont(font); n37.setCharacterSize(50); n37.setFillColor(Color::Black); n37.setStyle(Text::Bold); n37.setOrigin(10.f, 10.f); num = arr[2][6]; n37.setString(num);
//    n39.setFont(font); n39.setCharacterSize(50); n39.setFillColor(Color::Black); n39.setStyle(Text::Bold); n39.setOrigin(10.f, 10.f); num = arr[2][8]; n39.setString(num);
//
//    //4th line
//    Text n41, n42, n43, n44, n4, n45, n46, n47, n48, n49;
//    n41.setFont(font); n41.setCharacterSize(50); n41.setFillColor(Color(13, 43, 32)); n41.setStyle(Text::Bold); n41.setOrigin(10.f, 10.f); num = arr[3][0]; n41.setString(num); n41.setPosition(162, 275);
//    n45.setFont(font); n45.setCharacterSize(50); n45.setFillColor(Color(13, 43, 32)); n45.setStyle(Text::Bold); n45.setOrigin(10.f, 10.f); num = arr[3][4]; n45.setString(num); n45.setPosition(422, 275);
//    n42.setFont(font); n42.setCharacterSize(50); n42.setFillColor(Color::Black); n42.setStyle(Text::Bold); n42.setOrigin(10.f, 10.f); num = arr[3][1]; n42.setString(num);
//    n43.setFont(font); n43.setCharacterSize(50); n43.setFillColor(Color::Black); n43.setStyle(Text::Bold); n43.setOrigin(10.f, 10.f); num = arr[3][2]; n43.setString(num);
//    n44.setFont(font); n44.setCharacterSize(50); n44.setFillColor(Color::Black); n44.setStyle(Text::Bold); n44.setOrigin(10.f, 10.f); num = arr[3][3]; n44.setString(num);
//    n46.setFont(font); n46.setCharacterSize(50); n46.setFillColor(Color::Black); n46.setStyle(Text::Bold); n46.setOrigin(10.f, 10.f); num = arr[3][5]; n46.setString(num);
//    n47.setFont(font); n47.setCharacterSize(50); n47.setFillColor(Color::Black); n47.setStyle(Text::Bold); n47.setOrigin(10.f, 10.f); num = arr[3][6]; n47.setString(num);
//    n48.setFont(font); n48.setCharacterSize(50); n48.setFillColor(Color::Black); n48.setStyle(Text::Bold); n48.setOrigin(10.f, 10.f); num = arr[3][7]; n48.setString(num);
//    n49.setFont(font); n49.setCharacterSize(50); n49.setFillColor(Color(13, 43, 32)); n49.setStyle(Text::Bold); n49.setOrigin(10.f, 10.f); num = arr[3][8]; n49.setString(num);
//
//    //5th line
//    Text n51, n52, n53, n54, n55, n56, n57, n58, n59;
//    n53.setFont(font); n53.setCharacterSize(50); n53.setFillColor(Color(13, 43, 32)); n53.setStyle(Text::Bold); n53.setOrigin(10.f, 10.f); num = arr[4][2]; n53.setString(num); n53.setPosition(292, 340);
//    n57.setFont(font); n57.setCharacterSize(50); n57.setFillColor(Color(13, 43, 32)); n57.setStyle(Text::Bold); n57.setOrigin(10.f, 10.f); num = arr[4][6]; n57.setString(num); n57.setPosition(552, 340);
//    n51.setFont(font); n51.setCharacterSize(50); n51.setFillColor(Color::Black); n51.setStyle(Text::Bold); n51.setOrigin(10.f, 10.f); num = arr[4][0]; n51.setString(num);
//    n52.setFont(font); n52.setCharacterSize(50); n52.setFillColor(Color::Black); n52.setStyle(Text::Bold); n52.setOrigin(10.f, 10.f); num = arr[4][1]; n52.setString(num);
//    n54.setFont(font); n54.setCharacterSize(50); n54.setFillColor(Color::Black); n54.setStyle(Text::Bold); n54.setOrigin(10.f, 10.f); num = arr[4][3]; n54.setString(num);
//    n55.setFont(font); n55.setCharacterSize(50); n55.setFillColor(Color::Black); n55.setStyle(Text::Bold); n55.setOrigin(10.f, 10.f); num = arr[4][4]; n55.setString(num);
//    n56.setFont(font); n56.setCharacterSize(50); n56.setFillColor(Color::Black); n56.setStyle(Text::Bold); n56.setOrigin(10.f, 10.f); num = arr[4][5]; n56.setString(num);
//    n58.setFont(font); n58.setCharacterSize(50); n58.setFillColor(Color::Black); n58.setStyle(Text::Bold); n58.setOrigin(10.f, 10.f); num = arr[4][7]; n58.setString(num);
//    n59.setFont(font); n59.setCharacterSize(50); n59.setFillColor(Color::Black); n59.setStyle(Text::Bold); n59.setOrigin(10.f, 10.f); num = arr[4][8]; n59.setString(num);
//
//    //6th line
//    Text n61, n62, n63, n64, n65, n66, n67, n68, n69;
//    n69.setFont(font); n69.setCharacterSize(50); n69.setFillColor(Color(13, 43, 32)); n69.setStyle(Text::Bold); n69.setOrigin(10.f, 10.f); num = arr[5][8]; n69.setString(num); n69.setPosition(682, 405);
//    n61.setFont(font); n61.setCharacterSize(50); n61.setFillColor(Color::Black); n61.setStyle(Text::Bold); n61.setOrigin(10.f, 10.f); num = arr[5][0]; n61.setString(num);
//    n62.setFont(font); n62.setCharacterSize(50); n62.setFillColor(Color(13, 43, 32)); n62.setStyle(Text::Bold); n62.setOrigin(10.f, 10.f); num = arr[5][1]; n62.setString(num);
//    n63.setFont(font); n63.setCharacterSize(50); n63.setFillColor(Color::Black); n63.setStyle(Text::Bold); n63.setOrigin(10.f, 10.f); num = arr[5][2]; n63.setString(num);
//    n64.setFont(font); n64.setCharacterSize(50); n64.setFillColor(Color::Black); n64.setStyle(Text::Bold); n64.setOrigin(10.f, 10.f); num = arr[5][3]; n64.setString(num);
//    n65.setFont(font); n65.setCharacterSize(50); n65.setFillColor(Color(13, 43, 32)); n65.setStyle(Text::Bold); n65.setOrigin(10.f, 10.f); num = arr[5][4]; n65.setString(num);
//    n66.setFont(font); n66.setCharacterSize(50); n66.setFillColor(Color::Black); n66.setStyle(Text::Bold); n66.setOrigin(10.f, 10.f); num = arr[5][5]; n66.setString(num);
//    n67.setFont(font); n67.setCharacterSize(50); n67.setFillColor(Color::Black); n67.setStyle(Text::Bold); n67.setOrigin(10.f, 10.f); num = arr[5][6]; n67.setString(num);
//    n68.setFont(font); n68.setCharacterSize(50); n68.setFillColor(Color::Black); n68.setStyle(Text::Bold); n68.setOrigin(10.f, 10.f); num = arr[5][7]; n68.setString(num);
//
//    //7th line
//    Text n71, n72, n73, n75, n74, n76, n78, n77, n79;
//    n72.setFont(font); n72.setCharacterSize(50); n72.setFillColor(Color(13, 43, 32)); n72.setStyle(Text::Bold); n72.setOrigin(10.f, 10.f); num = arr[6][1]; n72.setString(num); n72.setPosition(227, 470);
//    n76.setFont(font); n76.setCharacterSize(50); n76.setFillColor(Color(13, 43, 32)); n76.setStyle(Text::Bold); n76.setOrigin(10.f, 10.f); num = arr[6][5]; n76.setString(num); n76.setPosition(487, 470);
//    n71.setFont(font); n71.setCharacterSize(50); n71.setFillColor(Color::Black); n71.setStyle(Text::Bold); n71.setOrigin(10.f, 10.f); num = arr[6][0]; n71.setString(num);
//    n73.setFont(font); n73.setCharacterSize(50); n73.setFillColor(Color::Black); n73.setStyle(Text::Bold); n73.setOrigin(10.f, 10.f); num = arr[6][2]; n73.setString(num);
//    n74.setFont(font); n74.setCharacterSize(50); n74.setFillColor(Color::Black); n74.setStyle(Text::Bold); n74.setOrigin(10.f, 10.f); num = arr[6][3]; n74.setString(num);
//    n75.setFont(font); n75.setCharacterSize(50); n75.setFillColor(Color::Black); n75.setStyle(Text::Bold); n75.setOrigin(10.f, 10.f); num = arr[6][4]; n75.setString(num);
//    n77.setFont(font); n77.setCharacterSize(50); n77.setFillColor(Color::Black); n77.setStyle(Text::Bold); n77.setOrigin(10.f, 10.f); num = arr[6][6]; n77.setString(num);
//    n78.setFont(font); n78.setCharacterSize(50); n78.setFillColor(Color::Black); n78.setStyle(Text::Bold); n78.setOrigin(10.f, 10.f); num = arr[6][7]; n78.setString(num);
//    n79.setFont(font); n79.setCharacterSize(50); n79.setFillColor(Color(13, 43, 32)); n79.setStyle(Text::Bold); n79.setOrigin(10.f, 10.f); num = arr[6][8]; n79.setString(num);
//
//    //8th line
//    Text n81, n82, n83, n84, n85, n86, n87, n88, n89;
//    n84.setFont(font); n84.setCharacterSize(50); n84.setFillColor(Color(13, 43, 32)); n84.setStyle(Text::Bold); n84.setOrigin(10.f, 10.f); num = arr[7][3]; n84.setString(num); n84.setPosition(357, 535);
//    n88.setFont(font); n88.setCharacterSize(50); n88.setFillColor(Color(13, 43, 32)); n88.setStyle(Text::Bold); n88.setOrigin(10.f, 10.f); num = arr[7][7]; n88.setString(num); n88.setPosition(617, 535);
//    n81.setFont(font); n81.setCharacterSize(50); n81.setFillColor(Color::Black); n81.setStyle(Text::Bold); n81.setOrigin(10.f, 10.f); num = arr[7][0]; n81.setString(num);
//    n82.setFont(font); n82.setCharacterSize(50); n82.setFillColor(Color::Black); n82.setStyle(Text::Bold); n82.setOrigin(10.f, 10.f); num = arr[7][1]; n82.setString(num);
//    n83.setFont(font); n83.setCharacterSize(50); n83.setFillColor(Color(13, 43, 32)); n83.setStyle(Text::Bold); n83.setOrigin(10.f, 10.f); num = arr[7][2]; n83.setString(num);
//    n85.setFont(font); n85.setCharacterSize(50); n85.setFillColor(Color::Black); n85.setStyle(Text::Bold); n85.setOrigin(10.f, 10.f); num = arr[7][4]; n85.setString(num);
//    n86.setFont(font); n86.setCharacterSize(50); n86.setFillColor(Color::Black); n86.setStyle(Text::Bold); n86.setOrigin(10.f, 10.f); num = arr[7][5]; n86.setString(num);
//    n87.setFont(font); n87.setCharacterSize(50); n87.setFillColor(Color::Black); n87.setStyle(Text::Bold); n87.setOrigin(10.f, 10.f); num = arr[7][6]; n87.setString(num);
//    n89.setFont(font); n89.setCharacterSize(50); n89.setFillColor(Color::Black); n89.setStyle(Text::Bold); n89.setOrigin(10.f, 10.f); num = arr[7][8]; n89.setString(num);
//
//    //9th line
//    Text n91, n92, n93, n94, n95, n96, n97, n98, n99;
//    n91.setFont(font); n91.setCharacterSize(50); n91.setFillColor(Color(13, 43, 32)); n91.setStyle(Text::Bold); n91.setOrigin(10.f, 10.f); num = arr[8][0]; n91.setString(num); n91.setPosition(162, 600);
//    n95.setFont(font); n95.setCharacterSize(50); n95.setFillColor(Color(13, 43, 32)); n95.setStyle(Text::Bold); n95.setOrigin(10.f, 10.f); num = arr[8][4]; n95.setString(num); n95.setPosition(422, 600);
//    n97.setFont(font); n97.setCharacterSize(50); n97.setFillColor(Color(13, 43, 32)); n97.setStyle(Text::Bold); n97.setOrigin(10.f, 10.f); num = arr[8][6]; n97.setString(num); n97.setPosition(552, 600);
//    n92.setFont(font); n92.setCharacterSize(50); n92.setFillColor(Color::Black); n92.setStyle(Text::Bold); n92.setOrigin(10.f, 10.f); num = arr[8][1]; n92.setString(num);
//    n93.setFont(font); n93.setCharacterSize(50); n93.setFillColor(Color::Black); n93.setStyle(Text::Bold); n93.setOrigin(10.f, 10.f); num = arr[8][2]; n93.setString(num);
//    n94.setFont(font); n94.setCharacterSize(50); n94.setFillColor(Color::Black); n94.setStyle(Text::Bold); n94.setOrigin(10.f, 10.f); num = arr[8][3]; n94.setString(num);
//    n96.setFont(font); n96.setCharacterSize(50); n96.setFillColor(Color::Black); n96.setStyle(Text::Bold); n96.setOrigin(10.f, 10.f); num = arr[8][5]; n96.setString(num);
//    n98.setFont(font); n98.setCharacterSize(50); n98.setFillColor(Color::Black); n98.setStyle(Text::Bold); n98.setOrigin(10.f, 10.f); num = arr[8][7]; n98.setString(num);
//    n99.setFont(font); n99.setCharacterSize(50); n99.setFillColor(Color::Black); n99.setStyle(Text::Bold); n99.setOrigin(10.f, 10.f); num = arr[8][8]; n99.setString(num);
//    //position
//    n99.setPosition(680, 600);
//    n98.setPosition(615, 600);
//    n96.setPosition(485, 600);
//    n94.setPosition(355, 600);
//    n93.setPosition(290, 600);
//    n92.setPosition(225, 600);
//    n89.setPosition(680, 535);
//    n87.setPosition(550, 535);
//    n86.setPosition(485, 535);
//    n81.setPosition(160, 535);
//    n83.setPosition(290, 535);
//    n85.setPosition(420, 535);
//    n82.setPosition(225, 535);
//    n51.setPosition(150, 340);
//    n61.setPosition(152, 405);
//    n62.setPosition(225, 405);
//    n63.setPosition(290, 405);
//    n64.setPosition(355, 405);
//    n65.setPosition(420, 405);
//    n78.setPosition(615, 470);
//    n79.setPosition(685, 470);
//    n67.setPosition(550, 405);
//    n52.setPosition(225, 340);
//    n73.setPosition(290, 470);
//    n66.setPosition(485, 405);
//    n54.setPosition(355, 340);
//    n77.setPosition(550, 470);
//    n56.setPosition(485, 340);
//    n55.setPosition(420, 340);
//    n58.setPosition(615, 340);
//    n59.setPosition(680, 340);
//    n68.setPosition(615, 405);
//    n74.setPosition(355, 470);
//    n75.setPosition(420, 470);
//    n11.setPosition(145, 70);
//    n12.setPosition(210, 70);
//    n13.setPosition(290, 80);
//    n15.setPosition(420, 80);
//    n17.setPosition(550, 80);
//    n18.setPosition(615, 80);
//    n21.setPosition(152, 145);
//    n23.setPosition(290, 145);
//    n24.setPosition(355, 145);
//    n25.setPosition(420, 145);
//    n26.setPosition(485, 145);
//    n27.setPosition(550, 145);
//    n28.setPosition(615, 145);
//    n29.setPosition(685, 145);
//    n31.setPosition(152, 210);
//    n32.setPosition(225, 210);
//    n33.setPosition(290, 210);
//    n34.setPosition(355, 210);
//    n35.setPosition(420, 210);
//    n37.setPosition(550, 210);
//    n39.setPosition(680, 210);
//    n42.setPosition(225, 275);
//    n43.setPosition(290, 275);
//    n44.setPosition(355, 275);
//    n46.setPosition(485, 275);
//    n47.setPosition(550, 275);
//    n48.setPosition(615, 275);
//    n49.setPosition(680, 275);
//    n71.setPosition(152, 470);
//    sf::Event event;
//    //game loop
//    while (window.isOpen())
//    {
//        //game is not finisned until all the correct inputs are stored in array
//        while (sudokuSolved == false)
//        {
//            while (window.pollEvent(event))
//            {
//                switch (event.type)
//                {
//                case sf::Event::Closed:
//                    window.close();
//                    break;
//                }
//            }
//            window.clear(sf::Color(61, 85, 65));
//            //Outer grid is shown after every third smaller grid 
//            for (int i = 2; i <= 10; i = i + 3)
//            {
//                for (int j = 1; j < 10; j = j + 3)
//                {
//                    grid1.setPosition(sf::Vector2f(gridSize * i, gridSize * j));
//                    window.draw(grid1);
//                }
//            }
//            //inner grids are skipped once every two times being drawn
//            int a = 1;
//            for (int i = 2; i < 11; i++)
//            {
//                if (a % 3 != 0)
//                {
//                    horizontal.setPosition(sf::Vector2f(gridSize * 2, gridSize * i));
//                    window.draw(horizontal);
//                }
//                a++;
//            }
//            a = 1;
//            for (int j = 3; j <= 10; j++)
//            {
//                if (a % 3 != 0)
//                {
//                    vertical.setPosition(sf::Vector2f(gridSize * j, gridSize));
//                    window.draw(vertical);
//                }
//                a++;
//            }
//            //drawing on window(GRAPHICS)
//            window.draw(n91); window.draw(n14); window.draw(n16); window.draw(n19); window.draw(n22);
//            window.draw(n38); window.draw(n36); window.draw(n41); window.draw(n45); window.draw(n53);
//            window.draw(n57); window.draw(n69); window.draw(n72); window.draw(n76); window.draw(n84);
//            window.draw(n88); window.draw(n91); window.draw(n95); window.draw(n97); window.draw(n14);
//            //s is declared as count to show error
//            int s = 0;
//            //ROW 1//
//            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
//            {
//                //innitially all bools are false as game is incomplete
//                bool checkR = false, checkC = false, checkB = false;
//                //to check the postion of mouse click
//                int x = event.mouseButton.x;
//                int y = event.mouseButton.y;
//                if (x >= 130 && x <= 195 && y >= 65 && y <= 130)
//                {
//                    //row and column declared according to index of array
//                    r = 0;
//                    c = 0;
//                    //function call to take input from player
//                    ch = input();
//                    //if a number between 1 and 9 is entered
//                    if (ch != ' ')
//                    {
//                        //function call if the number is present in corresponding row, column or grid
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else//if 0 is entered which works as space
//                    {
//                        //bools are declared true to store space in array
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        //storing the number in array if and only if it does not exist in row, column and grid
//                        n11.setString(ch);
//                        store(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        //if any one of the bools is false the count is given value of 1 
//                        s = 1;
//                    }
//                }
//                if (x >= 195 && x <= 260 && y >= 65 && y <= 130)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 0;
//                    c = 1;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n12.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//
//                }
//                if (x >= 260 && x <= 325 && y >= 65 && y <= 130)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 0;
//                    c = 2;
//                    ch = input();
//
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n13.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 390 && x <= 455 && y >= 65 && y <= 130)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 0;
//                    c = 4;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n15.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 520 && x <= 585 && y >= 65 && y <= 130)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 0;
//                    c = 6;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n17.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 585 && x <= 650 && y >= 65 && y <= 130)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 0;
//                    c = 7;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n18.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                //ROW 2//
//                if (x >= 130 && x <= 195 && y >= 130 && y <= 195)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 1;
//                    c = 0;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n21.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 260 && x <= 325 && y >= 130 && y <= 195)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 1;
//                    c = 2;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n23.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 325 && x <= 390 && y >= 130 && y <= 195)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 1;
//                    c = 3;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n24.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 390 && x <= 455 && y >= 130 && y <= 195)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 1;
//                    c = 4;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n25.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 455 && x <= 520 && y >= 130 && y <= 195)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 1;
//                    c = 5;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n26.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 585 && x <= 650 && y >= 130 && y <= 195)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 1;
//                    c = 7;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n28.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 650 && x <= 715 && y >= 130 && y <= 195)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 1;
//                    c = 8;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        cout << "T";
//                        store(arr, ch, r, c);
//                        n29.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//
//                //ROW 3//
//                if (x >= 130 && x <= 195 && y >= 195 && y <= 260)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 2;
//                    c = 0;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n31.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 195 && x <= 260 && y >= 195 && y <= 260)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 2;
//                    c = 1;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n32.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 325 && x <= 390 && y >= 195 && y <= 260)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 2;
//                    c = 3;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n34.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 390 && x <= 455 && y >= 195 && y <= 260)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 2;
//                    c = 4;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n35.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 520 && x <= 585 && y >= 195 && y <= 260)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 2;
//                    c = 6;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n37.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 650 && x <= 715 && y >= 195 && y <= 260)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 2;
//                    c = 8;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n39.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                //ROW 4
//                if (x >= 195 && x <= 260 && y >= 260 && y <= 325)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 3;
//                    c = 1;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n42.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 260 && x <= 325 && y >= 260 && y <= 325)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 3;
//                    c = 2;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n43.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 325 && x <= 390 && y >= 260 && y <= 325)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 3;
//                    c = 3;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n44.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 455 && x <= 520 && y >= 260 && y <= 325)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 3;
//                    c = 5;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n46.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 520 && x <= 585 && y >= 260 && y <= 325)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 3;
//                    c = 6;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n47.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 585 && x <= 650 && y >= 260 && y <= 325)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 3;
//                    c = 7;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n48.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                //ROW 5//
//                if (x >= 130 && x <= 195 && y >= 325 && y <= 390)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 4;
//                    c = 0;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n51.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 195 && x <= 260 && y >= 325 && y <= 390)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 4;
//                    c = 1;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n52.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 325 && x <= 390 && y >= 325 && y <= 390)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 4;
//                    c = 3;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n54.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 390 && x <= 455 && y >= 325 && y <= 390)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 4;
//                    c = 4;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n55.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 455 && x <= 520 && y >= 325 && y <= 390)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 4;
//                    c = 5;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n56.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 585 && x <= 650 && y >= 325 && y <= 390)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 4;
//                    c = 7;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n58.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 650 && x <= 715 && y >= 325 && y <= 390)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 4;
//                    c = 8;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n59.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                //ROW 6
//                if (x >= 130 && x <= 195 && y >= 390 && y <= 455)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 5;
//                    c = 0;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n61.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 260 && x <= 325 && y >= 390 && y <= 455)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 5;
//                    c = 2;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n63.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 325 && x <= 390 && y >= 390 && y <= 455)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 5;
//                    c = 3;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n64.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 455 && x <= 520 && y >= 390 && y <= 455)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 5;
//                    c = 5;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                        if (checkR)
//                            cout << "R";
//                        if (checkB)
//                            cout << "B";
//                        if (checkC)
//                            cout << "C";
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n66.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 585 && x <= 650 && y >= 390 && y <= 455)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 5;
//                    c = 7;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n68.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 520 && x <= 585 && y >= 390 && y <= 455)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 5;
//                    c = 6;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n67.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                //ROW 7//
//                if (x >= 130 && x <= 195 && y >= 455 && y <= 520)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 6;
//                    c = 0;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n71.setString(ch);
//                    }
//                }
//                if (x >= 260 && x <= 325 && y >= 455 && y <= 520)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 6;
//                    c = 2;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n73.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 325 && x <= 390 && y >= 455 && y <= 520)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 6;
//                    c = 3;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n74.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 390 && x <= 455 && y >= 455 && y <= 520)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 6;
//                    c = 4;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n75.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 520 && x <= 585 && y >= 455 && y <= 520)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 6;
//                    c = 6;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n77.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 585 && x <= 650 && y >= 455 && y <= 520)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 6;
//                    c = 7;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n78.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                //ROW 8//
//                if (x >= 130 && x <= 195 && y >= 520 && y <= 585)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 7;
//                    c = 0;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n81.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 195 && x <= 260 && y >= 520 && y <= 585)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 7;
//                    c = 1;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n82.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 390 && x <= 455 && y >= 520 && y <= 585)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 7;
//                    c = 4;
//                    n85.setPosition(420, 535);
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n85.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 455 && x <= 520 && y >= 520 && y <= 585)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 7;
//                    c = 5;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n86.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 520 && x <= 585 && y >= 520 && y <= 585)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 7;
//                    c = 6;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n87.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 650 && x <= 715 && y >= 520 && y <= 585)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 7;
//                    c = 8;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n89.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                //ROW 9
//                if (x >= 195 && x <= 260 && y >= 585 && y <= 650)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 8;
//                    c = 1;
//
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n92.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 260 && x <= 325 && y >= 585 && y <= 650)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 8;
//                    c = 2;
//
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n93.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//
//                if (x >= 325 && x <= 390 && y >= 585 && y <= 650)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 8;
//                    c = 3;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n94.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//
//                if (x >= 455 && x <= 520 && y >= 585 && y <= 650)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 8;
//                    c = 5;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n96.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 585 && x <= 650 && y >= 585 && y <= 650)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 8;
//                    c = 7;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n98.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                if (x >= 650 && x <= 715 && y >= 585 && y <= 650)
//                {
//                    bool checkR = false, checkC = false, checkB = false;
//                    r = 8;
//                    c = 8;
//                    ch = input();
//                    if (ch != ' ')
//                    {
//                        checkR = checkRow(arr, ch, r, c);
//                        checkC = checkCol(arr, ch, r, c);
//                        checkB = checkBox(arr, ch, r, c);
//                    }
//                    else
//                    {
//                        checkR = true;
//                        checkB = true;
//                        checkC = true;
//                    }
//                    if (checkR && checkC && checkB)
//                    {
//                        store(arr, ch, r, c);
//                        n99.setString(ch);
//                    }
//                    else
//                    {
//                        s = 1;
//                    }
//                }
//                //if count is 1 then error window pops up
//                if (s == 1)
//                {
//                    sf::RenderWindow error1(sf::VideoMode(350, 170), "Error", sf::Style::Titlebar | sf::Style::Close);
//                    sf::Event event1;
//                    while (error1.isOpen())
//                    {
//                        while (error1.pollEvent(event1))
//                        {
//                            switch (event1.type)
//                            {
//                            case sf::Event::Closed:
//                                error1.close();
//                                break;
//                            case sf::Event::MouseButtonPressed:
//                                error1.close();
//                                break;
//                            case sf::Event::KeyPressed:
//                                error1.close();
//                                break;
//                            }
//                        }
//                        error1.clear(sf::Color(64, 130, 109));
//                        error1.draw(text2);
//                        error1.draw(erTxt);
//                        error1.display();
//                    }
//                }
//            }
//            window.draw(n13); window.draw(n14); window.draw(n15); window.draw(n17); window.draw(n18); window.draw(n19);
//            window.draw(n21); window.draw(n22); window.draw(n23); window.draw(n24); window.draw(n25); window.draw(n26);
//            window.draw(n27); window.draw(n28); window.draw(n29); window.draw(n31); window.draw(n32); window.draw(n34);
//            window.draw(n33); window.draw(n35); window.draw(n37); window.draw(n39); window.draw(n42); window.draw(n43);
//            window.draw(n44); window.draw(n46); window.draw(n47); window.draw(n48); window.draw(n49); window.draw(n51);
//            window.draw(n52); window.draw(n54); window.draw(n55); window.draw(n56); window.draw(n45); window.draw(n58);
//            window.draw(n59); window.draw(n61); window.draw(n62); window.draw(n63); window.draw(n65); window.draw(n66);
//            window.draw(n64); window.draw(n67); window.draw(n68); window.draw(n71); window.draw(n73); window.draw(n74);
//            window.draw(n76); window.draw(n77); window.draw(n78); window.draw(n79); window.draw(n81); window.draw(n82);
//            window.draw(n83); window.draw(n85); window.draw(n86); window.draw(n87); window.draw(n89); window.draw(n91);
//            window.draw(n92); window.draw(n93); window.draw(n94); window.draw(n96); window.draw(n97); window.draw(n98);
//            window.draw(n12); window.draw(n99); window.draw(n11); window.draw(text); window.draw(n75);
//            //checking if sudoku is solved or not
//            sudokuSolved = checkSudoku(arr);
//            //if the player wants to save the game they can press s and save window pops up
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//            {
//                sf::RenderWindow save(sf::VideoMode(400, 200), "Save Game", sf::Style::Titlebar | sf::Style::Close);
//                while (save.isOpen())
//                {
//                    sf::Event event2;
//                    while (save.pollEvent(event2))
//                    {
//                        switch (event2.type)
//                        {
//                        case sf::Event::Closed:
//                            save.close();
//                            break;
//                        }
//                    }
//                    save.clear(sf::Color(64, 130, 109));
//                    save.draw(saveT);
//                    save.draw(saveTx);
//                    save.display();
//                    //if player press y
//                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
//                    {
//                        //the array is stored in txt file 
//                        ofstream sudokuGame;
//                        sudokuGame.open("sudoku game.txt");
//                        if (!sudokuGame)
//                        {
//                            cout << "Error";
//                        }
//                        else
//                        {
//                            for (int i = 0; i < 9; i++)
//                            {
//                                for (int j = 0; j < 9; j++)
//                                {
//                                    //in case of space 0 is stored
//                                    if (arr[i][j] != ' ')
//                                    {
//                                        num = arr[i][j];
//                                    }
//                                    else
//                                    {
//                                        num = 0;
//                                    }
//                                    sudokuGame << num;
//                                }
//                            }
//                            sudokuGame.close();
//                        }
//                        save.close();
//                    }
//                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
//                    {
//                        save.close();
//                    }
//                }
//            }
//            window.display();
//            //when the game is finined
//            if (sudokuSolved)
//            {
//                sf::RenderWindow finish(sf::VideoMode(350, 165), "Game Finished", sf::Style::Titlebar | sf::Style::Close);
//                while (finish.isOpen())
//                {
//                    sf::Event event2;
//                    while (finish.pollEvent(event2))
//                    {
//                        switch (event2.type)
//                        {
//                        case sf::Event::Closed:
//                            finish.close();
//                            break;
//                        case sf::Event::KeyPressed:
//                            finish.close();
//                            break;
//                        }
//                    }
//                    finish.clear(sf::Color(64, 130, 109));
//                    finish.draw(fin);
//                    finish.draw(text1);
//                    finish.display();
//                }
//            }
//        }
//    }
//    return 0;
//}
//char input()
//{
//    //keep taking input as long as the numbers are not entered
//    char ch = _getch();
//    if (ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7' && ch != '8' && ch != '9')
//    {
//        while (ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7' && ch != '8' && ch != '9')
//            ch = _getch();
//    }
//    if (ch == '0')
//    {
//        ch == ' ';
//        return ' ';
//    }
//    return ch;
//}
//bool checkRow(char arr[9][9], char ch, int r, int c)
//{
//    //row is checked if the number exists in it or not 
//    for (int i = 0; i < 9; i++)
//    {
//        if ((arr[i][c] == ch) && (i != r))
//        {
//            return false;
//        }
//    }
//    return true;
//}
//bool checkCol(char arr[9][9], char ch, int r, int c)
//{
//    //column is checked if the number exists in it or not 
//    for (int j = 0; j < 9; j++)
//    {
//        if (arr[r][j] == ch && (j != c))
//        {
//            return false;
//        }
//    }
//    return true;
//}
//bool checkBox(char arr[9][9], char ch, int r, int c)
//{
//    int i, j, a = 0, b = 0;
//    //outer grid consists of three inner boxes. Subtracting the mod of 3 from the
//    //corresponding row and column so our pointer is at start of the corresponding grid
//    if (r % 3 == 0)
//    {
//        a = r;
//    }
//    else if (r % 3 == 1)
//    {
//        a = r - 1;
//    }
//    else if (r % 3 == 2)
//    {
//        a = r - 2;
//    }
//    if (c % 3 == 0)
//    {
//        b = c;
//    }
//    else if (c % 3 == 1)
//    {
//        b = c - 1;
//    }
//    else if (c % 3 == 2)
//    {
//        b = c - 2;
//    }
//    for (i = a; i < a + 3; i++)
//    {
//        for (j = b; j < b + 3; j++)
//        {
//            //check every box except in which number is entered
//            if (arr[i][j] == ch && (i != r || j != c))
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//void puzzle(char arr[9][9])
//{
//    int n;
//    srand(time(0));
//    n = rand() % 3;
//    if (n == 0)
//    {
//        char ar[9][9] = { {' ',' ',' ','2',' ','9',' ',' ','1'},
//                      {' ','8',' ',' ',' ',' ','4',' ',' '},
//                      {' ',' ','7',' ',' ','4',' ','6',' '},
//                      {'8',' ',' ',' ','9',' ',' ',' ','7'},
//                      {' ',' ','4',' ',' ',' ','9',' ',' '},
//                      {' ','5',' ',' ','4',' ',' ',' ','8'},
//                      {' ','1',' ',' ',' ','6',' ',' ','4'},
//                      {' ',' ','8','9',' ',' ',' ','3',' '},
//                      {'7',' ',' ',' ','1',' ','2',' ',' '} };
//        for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                arr[i][j] = ar[i][j];
//            }
//        }
//    }
//    if (n == 1)
//    {
//        char ar[9][9] = { {' ',' ',' ','8',' ','6',' ',' ','7'},
//                          {' ','9',' ',' ',' ',' ','6',' ',' '},
//                          {' ',' ','7',' ',' ','3',' ','2',' '},
//                          {'7',' ',' ',' ','5',' ',' ',' ','3'},
//                          {' ',' ','6',' ',' ',' ','2',' ',' '},
//                          {' ','2',' ',' ','8',' ',' ',' ','1'},
//                          {' ','3',' ',' ',' ','8',' ',' ','6'},
//                          {' ',' ','1','3',' ',' ',' ','8',' '},
//                          {'2',' ',' ',' ','6',' ','3',' ',' '} };
//        for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//                arr[i][j] = ar[i][j];
//        }
//    }
//    /*if (n == 2)
//    {
//        char ar[9][9] = { {' ',' ',' ','3',' ','5',' ',' ','7'},
//                      {' ','6',' ',' ',' ',' ','3',' ',' '},
//                      {' ',' ','7',' ',' ','6',' ','1',' '},
//                      {'8',' ',' ',' ','3',' ',' ',' ','2'},
//                      {' ',' ','1',' ',' ',' ','5',' ',' '},
//                      {' ','4',' ',' ','2',' ',' ',' ','6'},
//                      {' ','1',' ',' ',' ','3',' ',' ','5'},
//                      {' ',' ','6','1',' ',' ',' ','3',' '},
//                      {'5',' ',' ',' ','6',' ','7',' ',' '} };
//        for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                arr[i][j] = ar[i][j];
//            }
//        }
//    }*/
//    if (n == 2)
//    {
//        char ar[9][9] = { {' ',' ',' ','4',' ','7',' ',' ','8'},
//                          {' ','2',' ',' ',' ',' ','7',' ',' '},
//                          {' ',' ','8',' ',' ','2',' ','4',' '},
//                          {'4',' ',' ',' ','3',' ',' ',' ','1'},
//                          {' ',' ','7',' ',' ',' ','4',' ',' '},
//                          {' ','5',' ',' ','7',' ',' ',' ','9'},
//                          {' ','8',' ',' ',' ','6',' ',' ','2'},
//                          {' ',' ','3','9',' ',' ',' ','8',' '},
//                          {'7',' ',' ',' ','2',' ','1',' ',' '} };
//        for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                arr[i][j] = ar[i][j];
//            }
//        }
//    }
//}
//void store(char arr[9][9], char ch, int r, int c)
//{
//    arr[r][c] = ch; //storing the character in array
//}
//bool checkSudoku(char arr[9][9])
//{
//    //once a number is stored the game is checked if it is solved or not
//    bool row = false, col = false, box = false, empty = false;
//    for (int i = 0; i < 9; i++)
//    {
//        for (int j = 0; j < 9; j++)
//        {
//            //each grid, column and row should have unique number and should not be empty
//            box = checkBox(arr, arr[i][j], i, j);
//            row = checkRow(arr, arr[i][j], i, j);
//            col = checkCol(arr, arr[i][j], i, j);
//            empty = emp(arr);
//            if ((row && col) && (box && empty))
//            {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//bool emp(char arr[9][9])
//{
//    for (int i = 0; i < 9; i++)
//    {
//        for (int j = 0; j < 9; j++)
//        {
//            if (arr[i][j] == ' ')
//                return false;
//        }
//    }
//    return true;
//}