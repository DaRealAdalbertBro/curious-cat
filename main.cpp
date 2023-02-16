#include <iostream>

#ifdef __unix__
#include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#define sleep(x) Sleep(x)
#endif

// Console Application for spinning a cat in a circle
namespace CatAnimation
{

    class CatAnimator
    {
        int m_frame;
        int m_play_speed;

    public:
        CatAnimator()
        {
            m_frame = 0;
            m_play_speed = 90;
        }

        void animate()
        {
            frame1();
        }

    private:
        void clearConsole()
        {
            HANDLE hStdOut;
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            DWORD count;
            DWORD cellCount;
            COORD homeCoords = {0, 0};

            hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hStdOut == INVALID_HANDLE_VALUE)
                return;

            // Get the number of cells in the current buffer
            if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
                return;
            cellCount = csbi.dwSize.X * csbi.dwSize.Y;

            // Fill the entire buffer with spaces
            if (!FillConsoleOutputCharacter(
                    hStdOut,
                    (TCHAR)' ',
                    cellCount,
                    homeCoords,
                    &count))
                return;

            // Fill the entire buffer with the current colors and attributes
            if (!FillConsoleOutputAttribute(
                    hStdOut,
                    csbi.wAttributes,
                    cellCount,
                    homeCoords,
                    &count))
                return;

            // Move the cursor home
            SetConsoleCursorPosition(hStdOut, homeCoords);
        }

        void frame1()
        {
            m_frame++;
            clearConsole();
            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGPPPPPPPPPPPPPPP5555555555555555555YY5555555555YYY5PPPPPPPGGGGGGGGGGGG\n"
                         "GGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGP5J????JJ?77???7777??7777??777!7777777?JY5YJJY5PPGGGGBBBB\n"
                         "BBBBBBBBBBBBBB######################BBBBBG5J???77!!!777!!!!!7!!!!77!!!!777!!!!!77777???????J5PGBBB##\n"
                         "#BBBBBBBBBBBB#########################BBG5J?777777777!!!!!!!!!777!!!7777!!7777!!!77777777??JYPGBB###\n"
                         "#GJ??Y5PGBBBB#########################BYJ?7!!7JYJ?77777!!!!!7!!!!!77!!!!777!!777777777777!7?YPGB####\n"
                         "BPJ7!~!7?YPGBB#######################BGY77!!7?Y5PPPYJ77!!7!!!!7777!!!7777!!!7777777777!77???J5PGB###\n"
                         "##BGPY7!~~!?Y5PGBBBB################BBPJ77!!!!77?J55YYJ?7!!!!77!!!7777!!7777!!77777777???JJYY5PGB###\n"
                         "######BG5?7!!!?JY5YYYPGBBBBBB####BBBBBPJ77!!!777777???????777!!!777777777!!77777!77777???JY5GBB#####\n"
                         "&&&&######BPY?7!!777?JJY5PGBBGP5PPGGBBPJ7!!!!!!!77????????7!7777!!!7?77!77??777???777?JY5PGB#######&\n"
                         "&&&&&&&&&&###BG5J?7!!77???JJJ?7!!7?J5GPJ77!!!!!!!!!!??JJJJ?77!!!7?JJJJYJJJJJJJJJJJJJJYPGBB#######&&&\n"
                         "&&&&&&&&&&&&#####BP5J77!!!!~~~~~!!~~7Y5J!!!!!!!!!!!!!!!77?7!!77?J55YJJYP5YJJY55YJ???7J5BB#######&&&&\n"
                         "&&&&&&&&&&&&&&&&&&##BG5J7~^~~~~~~~!!?5PPY?7!~!!!!!~!!!!!~!!77777?JJ?777?J???????77?JJYPB#####&&&&&&&\n"
                         "@@@@@@@@@@@&&&&&&&&&###Y~^^^^^^^^~~!7YPPYJ7~~!!~~~~!!~~~~!~~~~!7!!!!!7!!!!!77!!!!?JJY5G##&&&&&&&&&&&\n"
                         "@@@@@@@@@@@@@@@@&&&&&&#GYJJY55YJJY55PGBBBG5YYY55YYYY55YYYYY55YY5555YY55555Y5PPP555PGB##&&&&&&&&&&&&&\n"
                         "@@@@@@@@@@@@@@@@&@&@&&&&&#&###########&#############################################&&&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame2();
        }

        void frame2()
        {
            m_frame++;
            clearConsole();
            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555PPP55555P5555PPP5555PP55555PPPPPGGGGGGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBGGGGGGGGGGP55YJ??JYYJ???JJ????JJJ777?JJ?777???777?JYPGGGGGGGGBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBB#############B#BBBBBBBPJ77??77!!7777!!!!777!!!!77!!!!77!!!!777777JY5PPGGBBBBBB##\n"
                         "BBBBBBBBBBBBBB########################BBBGPYJ?77!7777!!!!!7!!!!777!!!!77!!!!777!!!7???J???J5PGGBBB##\n"
                         "BG5Y5GGBBBBBBB#########################GP5J7!!!?J?7!!777!!~!777!!!777!!!7777!!!777!!!7??77!77?Y5GGB#\n"
                         "B57~~7?J5PGBB#########################BP?!!777?YPP5YJ?77777!!!!777!!!777!!!!777!!777777!7777777?Y5PB\n"
                         "BGYJ?!~~!7J5PGBB#####################BBPY?7!!!7J5PPP5YJ?7!!!777!!!777!!!777!!!!7777777777777???JJYPB\n"
                         "#BGP55YJ7!~!!?Y5PP5YY5PGBB###########BBPJ7!!!7?Y5PPP5?7!!777!!!!!!!!!7777!!!777!!!7777777?????J5PGB#\n"
                         "###BBGBBBP5J7!!7?J7!!7?JYPGBBBBBBBBBBBBPY?77!!!7??YPGP5Y?7!7777!!!7777!!777777777777777????Y5PGB####\n"
                         "&&&&&&&&###BG5Y?!!7JY?!!!7?Y5P5J?JY5PGGPJ7!!!!!7!!77JY5YJJ?7!!7777!7!7??77777??7777???7?Y5PGBB######\n"
                         "&&&&&&&&&&&&###BGGPGBGPYJ7!~~!7!~~!!7J5PJ77!!!!!77!!!!777777!7!!77?JJ?7?J55J???Y5YJ????J5GBB#######&\n"
                         "&&&&&&&&&&&&&&&&&######GY7!!~~~~~!!!!7Y5Y7!!!!!!!!!!!!!!!!7777?Y555YY5PP5PPPPPPP5YJ????J5GB#######&&\n"
                         "@@@@@&&&&&&&&&&&&&&####GY!~^^~~~^^~~!?Y55J?7!~~!!!~~~!!!!~~!!7?Y5Y?7?JYY???JY5Y???77?YPGBB###&&&&&&&\n"
                         "@@@@@@@@@@@&&&&&&&&&&##G?~^~~~~^^~~!!7JYYJ?7!~!7!!~!!77!!!!7!!!!!777!!!777!!!7???77?J5GB##&&&&&&&&&&\n"
                         "@@@@@@@@@@@@@@@@@@&&&&&#GP55PPP555PPGGBBBBGPPPPPGPPPPPGGPPPPGGGPPPGGPPPPGGGGPPGGGGGGGB#&&&&&&&&&&&&&\n"
                         "@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&###&&&&&#####################&&&&###&&&&####&#######&&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame3();
        };

        void frame3()
        {
            m_frame++;
            clearConsole();
            std::cout << "GGPPGGGGGGGGGGGGGGGGGGGGGGGGGGGPPPPPGGGPPPP5YYJJYYYYJJJYYYYJJJYYYJJJJYYYJ??JJY5PPPGGGGGGGGGGBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP5YJ??777777777777777!!!!777!!!77777!!!7?Y5PGGGGGBBBBBBBBBBBB\n"
                         "BBBBBBBB#####################BBBBBBBBGPYJ?77777777!!!!7!!!!!!!!!!!!!!!!!!!!7777!!7?Y5PPGGBBBBBB#####\n"
                         "BBBBBBBBB########################BBBGPYJ?77777777!!7!!!!!!!!!!!!!77!!!!777!!77777!!!7?J5PPGGBBB#####\n"
                         "GPGBBBBBBBBB######################BGPY??7!!7?JYY?77777!!!!!!!!7!!!!!777!!7777!!!77777777?JY5PGGBB###\n"
                         "J7?J5PGPJY5PGBBBBGGBBBB#########BG5JJ?7!!7?Y55P5J???7!!!!!!!!!!!777!!!!77!!!!777777777777777?Y5GGBB#\n"
                         "J?7!!7??7777??Y55?77?J5GBBBBB##BBGY?7!!!7?Y5PPPY?777777!!!!7777!!!!777!!!777!!!777777777777777?J5GB#\n"
                         "BGPY?7!7JYJ7!7?Y5J7!!!7?J5GBBBBBBPY?77!!!!7??Y5PP5Y?7!!!!77!!!!!!!!!!77777!!!77777!777777777777?YGB#\n"
                         "&###BGPPGGGP55PPGG5YJ7!77JPGGPGGBGJ7!!!!!77!!7?Y5P5Y?77!!!77777!!77777777777777777777777777777??YGB#\n"
                         "&&&&&############BBG5J7?JYYY?7?JY5Y?7!!!!!!7777?Y5YJ?!7!!77!!!7777!!!7777!!!77777777777777777?JY5GB#\n"
                         "&&&&&&&&&&&&&&#####B5J?7!~!!~~~~!77!!!!!!!!!!!7?JYYJ?77!!!!!!!!!!!77?77!!!!!77!!777777777???J5GGB###\n"
                         "&&&&&&&&&&&&&&&&&##B5?7!~~~~~~~~!!7?JJ?7!!!!!!!!!7777!!!!!!77777??77JY5YJ?7!777777777???JY5PBB#####&\n"
                         "@@@&&&&&&&&&&&&&&##B5?~^^~~~~~~~~!7???77!!~~~~~~!!!!~!!!~!7JYJ77?YY5YY5555YJ?7777777?J5PGBB####&&&&&\n"
                         "@@@@@@@&&&&&&&&&&&#BY!^~~~~^^~!!!777777!!~~~!!!!~!!!7!!~!7J55J77?Y55?77JYPGGP5Y??77?J5B####&&&&&&&&&\n"
                         "@@@@@@@@@@@@@&&&&&&#G5Y55PP555555PPPPPPP55555PGP5555PPP555PGGP555PGBGPPGBB###BBGGGGGGB##&&&&&&&&&&&&\n"
                         "@@@@@@@@@@&&&&&&&&&&&##&########################################B#####################&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame4();
        }

        void frame4()
        {
            m_frame++;
            clearConsole();
            std::cout << "PPPPPPPGPPPGGGGGPPPPPPPP55PPPPGGGGPPPPPPPP5555555YYYY55YYYY55YYJJY5YYJJYYYYJJJY5PPPGGGGGGGBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBGP5YY?JJ????JY5PGGGGGGPP5YJJJJ??77777??777777777777777777777777?JY5PGGGGBBBBBBBBBBBB\n"
                         "################BBG5J77?YYJ?777?JYPGGGGP5J?7777777!!7777!!!7!!!!!!!!!7777777777777??YPGBBBBBB#######\n"
                         "####################BBGGBBBGPYJ?777JYPPP5YJ?7!!7777!!!7777!!!!77!!!777777777777777??Y5PGGGBBBB######\n"
                         "##############################BG5Y?7??JYYJJ??77777777777777!7!!!7777!!7777777777777?JY55YY5PGGB#####\n"
                         "&&#####&&&&&&&&&&&&&&##########BG5YJJJ??777?JY55Y?777!77!!!!77777777777777777777777777?JJJJJY5PBB###\n"
                         "&&&##&&&&&&&&&&&&&&&&&#########BG5YJJJ??77?Y5PPPY?77777!!!!7777!!7777777777777777777777777??JYPGB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&########BPJ77777!!!7?JY5P5YJ?77!777!!!!777!!!77777777777777?77777??77?YPGB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&######BG5?7!!~!!!!!!!77JY5P5YJ?7777777!!777!!777777!!77777777?7777?JYPGB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&###BGP?7!!!!~!!!!!!!!!!!7JYYJ?77777!!7777!!!77777777777777777???????JYPB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&##GJ7!!~~~~~!~~~!!!!!!!!7JY5YJ??7!7777!!!7777!!!7777777777777????JYPGGB####&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&#BY!~~~~~~~~~~~~~~~!!!~~~!7?7!!777!!!!!7!777777777777777777???J5PGB######&&&\n"
                         "&&&&&&@@&&&&&&@@&&&&&&&&&BY!~!!!!!!!!!7777777!!!777777777777??7?JY55YJY5P5Y?777???JYPGBB###&&&&&&&&&\n"
                         "&&&&@@@@@@@@@@@@@@@@&&&&&&BPPPPGPPPPPPPPPPPGPPPPPPPPPPPPGGGPPGGGBBBBBBB###BBGPPPPGBB#####&&&&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&###########################################################&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame5();
        }

        void frame5()
        {
            m_frame++;
            clearConsole();
            std::cout << "GGPPPPPPPPPPPPPPPPPPPPPGGGGGGGGPPPPGGGPPPP5555555YYYY55YYYYYYYYYYYYYYYJJJYYYJ??JJY5PPGGGGGGGGGGGBBBB\n"
                         "BBBGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBGGGP5YJ????77777??777777777777777777777777777?JY5PPGGGBBBBBBBBB\n"
                         "################################BBBBBBGP5J?777!!!7777777777!!!!!!!!!!!77!!!!!!!!!!!777?YPGBBBBBBBB##\n"
                         "###################################BGPJ?777!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7777777?J5PPGGGGBBB##\n"
                         "#################################BBGPY?7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!777777777777?JYYYJJY5PGGBB\n"
                         "#########&&&&#################B#BBBG5J7!!!77?JJJ?7!!!!!!!!!!!!!!!!!!!!7777!77777!!777777??????JJY5PB\n"
                         "####&&&&&&&&&&&&&&&&&#########BBBG5J?7!!7?J5555YJ77!!!!!!!!!!!!!!!!7777!!!7777!!7777777777777??J5PGB\n"
                         "&&&&&&&&&&&&&&&&&&&&&#########BBBPY?7!!!7?JY55P5J?77!!!!!!!!!!!!77777!!777777777777777777777?JYPGBB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&######BBBBP5Y?7!!!!!!!77?YY55YY?77!!!!!!!77!!77777!!!7777!!!77777777777??YGB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&####BG55J7!!!!!!!!!!!!!!!7JY5YJ?777!!!!!!!!7!!!!!7777!!77!!777777777??J5GBB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&##BGPY?!~~~~~~!!!!!!!!!!!!7?Y5YJ??77!!!!!77!!!!77!!!7777!!!!7777777?JYPGBBB####\n"
                         "&&&&&&&&&&&&&&&&&&&&##B5?!!~~~~~~~~~!!!~~~!!!!!!7JY555YJ?77!!!!77!!!!7777!!!!777777777777?YPB#######\n"
                         "&&&&&&&&&&&&&&&&&&&&&#GJ!~~~~~~~~~~~~~~~~~~~~~~~!!!7????7!!!!!!!!!77777777?7777!777777??JYPBB####&&&\n"
                         "@@@&&&&&&&&&&&&&&&&&&#GJ!~!777!!!!7777777??77!7777777777777!77??JY555YJJY5P5YJ?77??JJY5PGB####&&&&&&\n"
                         "@@@@@@@@@@@@&&&&@&&&&&#BPPPGGPPPPPPPPPPPPGGGPPPGPPGGGPPGGGPPPGGBBBBBBBBBB##BBBGPPPPGBB####&&&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&#################################################################&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame6();
        }

        void frame6()
        {
            m_frame++;
            clearConsole();
            std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBGGGP5YY????JJJ?77?JJ?777?JJ?777????777?JYY55YYY5555YJJYPBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP5J7!!!77!!!!!77!!!!!77!!!!777!!!777!!!7?JJ?77?????7??5BBB#\n"
                         "######################################BGP5YYJ?7!!!7777!!!!77!!!!!77!!!!777!!!7777!!!77777!7?JY5PBB##\n"
                         "#####################################BBG5YY?7!!!777!!!7777!!!777!!!!77!!!!7777!!!7?77!!7???77?JPBB##\n"
                         "###################################BBGP5J7!!77!!!!!!77!!!7777!!!7777!!!777!!!7777!!!7??777?JY5PBB###\n"
                         "&&&&&&&&&&&&&&&&&&################BBG5JJJ??7!!!!77!!!7777!!!!777!!!7777!!!7777!!77777777??J5PGB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&###########BBGP5J?7!!!!7?!!!!777!!!!777!!!777!!!7777!!!7??7!!777?777?YPBB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&#######BBBBBBG5?!!!!77?JJ?JJ?!!!777!!!!7777!77777!!!7?77!!77777!77?JY5GBB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&#####BBGPYJY5P5Y?7!!!7?JJY5P5YJ?7!!7777!!!7777!!!7777!!7777!!!7??777?YGBB####&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&###BG5J?7~~~!?J7!!!!7777?JYP5YYYJ??!!!!777!!!7777!!!777!!!77?77777JJYPGB###&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&###G5J?!~~~~!!~~~!!7!!!!7??JYPPP5YJ777777!!!777!!!!7777!!77?77777??J??YPB###&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&##BY7~~~!!!~~~~!!!~~!!7!~~!7?JY5PPP5J?!!!!77!!!!777!!!7?77!!7JJ?77?JYPGB###&&&&&\n"
                         "@@@@@@@@@@&&&&&&&&&&&#BY7~~~~~~^~~~~~~~~~~~~~~~!!!!7??Y55J??77!!!!7!!!!7???777JJYYJJ?JJ5GB##&&&&&&&&\n"
                         "@@@@@@@@@@@@&&&&&&&&&&#P???JYJ???JJJJJJJYYYJ??JJYYJJJJ5PP55PP55YYJYY5555PPPPPPGBGGPPPPGGB#&&&&&&&&&&\n"
                         "@@@@@@@@@@@@&&&&&&&&&&&&#######BBBBBBBBB#########################BB#####################&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame7();
        }

        void frame7()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGPPGGPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP5YJYY55YYYY55YYYY55YJJYY5YJ??JYYJJJJYYY???JYJ???JY5PGGBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5?77!77777!!777!!!!!77!!!!777!!!777!!!777!!!!77777?YPBBBB\n"
                         "########################################BBGY?77!!!!!!!77!!!!77!!!!77!!!!777!!!!77!!!!777!!7?J5PGB###\n"
                         "##########################################BY?7!!!!!7!!!!!77!!!777!!!!77!!!!7777!!!777!!77?JYPGBB####\n"
                         "##########################################BY7!!!!!!!!777!!!777!!!!777!!!777!!!7777!!77777!7JPGBB####\n"
                         "########&&&&&&&&&#&####################BBBB5?7!!!!777!!!777!!!!77!!!!777!!!777!!!77777777?JYPGB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&###########BBBBBBB57!!!!7!!!!77!!!!777!!!777!!!777!!!7777!!77777!7?JYPGB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#####BB##BBBBBBBG5J7!!!!!777!!!77!!!!777!!!777!!!7777!!7777!!7777777JPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&####BBGGGBBBGGPYJ?!!!!77!!!!777!!!777!!!!77!!!7777!!!7777!7777777??J5GB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&###BPY77?J5Y?77!!!!!!!!!7JY?7!?JY?7!!777!!!!7777!!777!77JYJ?7?JYJ?7?JPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&##B5?77~~~~!!~~7?YJ7!!!!7JY5PPP55PPP5J7!!!777!!777777?Y555PGPP5555YJY5GB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#GJ!~~~~~~~~~!7?J?7!!!~!!!7?Y5J?7JYY5PPY7!!!77!!!?Y5YYYY??JJJJ????JJ5B##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#P7~~!7!~~~!77777777!!!777!!!!777!!!?5PY77?777!!7J5J7!7?J?7!7?JJJ5GB#&&&&&\n"
                         "@@@@@@@@@@@@@@@@@@@&&&&&&&&#GPPGGGPPPPGGGGGGGGGPPPPGGGPPPGGGPPGGBBGGGGGGPPPGGGGPGGBBGGGGBB###&&&&&&&\n";

            sleep(m_play_speed);
            frame8();
        }

        void frame8()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPGGGGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555PP5555PP55555PP5555PP5YYY5P5YYY5PPGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBGGPPPPPP5YYY5P5YYJ?777?J?777???7777??77777??7777??77?J5GBBBBBBB\n"
                         "BBB#####BBBBBBB#B#################BBBBGP5JJ??7!!!777!!!!77!!!!!7!!!!!77!!!!77!!!!777!!!77?Y5GBB#B###\n"
                         "#####################################BG5J?7!!!!77!!!!77!!!!777!!!!77!!!!777!!!7777!!7777!?YPGBB#####\n"
                         "#####################################BPJ7!!!7!!!!!77!!!!777!!!!77!!!!77!!!!7777!!7777!!77?Y5PGB#####\n"
                         "#####################################BGY?7!!!!!!7!!!!777!!!777!!!777!!!7777!!!77777777777!!7?5GB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&##########BBBBBGY?!!!77!!!!!7!!!!77!!!!!7!!!!!777!!!777!!!77777!77777?YPB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&########BBBBGG5?777!!!!77!!!77!!!!!77!!!77777!77777!!77777777777777?YGB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&####BBBGPPY??7!!!!!!!!!!!77!!!!!!!!!!7777!77777777777777777??YYJJ?J5GB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&##BBGP5J!!!!!77??7!!!!777!!!!77!!!!!77!!!7!77777777!!!77?JY55YYJ?7?YPB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&###BGJ!!!!!!!!!7J?7!!!77JY5Y?7!!!!777!!!77!!!7777!!77??J5P5YY?777??JYPB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&##BGPJ77!~~!!!7?YYJ77!!7?JY5PP5J?J5P5Y?7!!!777!!!7??J555YY?777??77!?YGB##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&##GY7!!~~~~~~~~!777!!!!!!!!!7?J5PPY?J5GPJ!!!!!!!!77777?J?!!!7!!!!7?JYPB#&&&&\n"
                         "@&@&&&&&&&&&&&&&&&&&&&&&&#GJ77?JJ?77??JJJ?JYJJ???JJJ???Y55J7?J55YJJJJJJ??JYYJ??JYYYJ?JJY5PGB#&&&&&&&\n"
                         "@@@@@@@@@@@@@@@@&&&&&&&&&&&########BBBBBBB####BBBBB########BBB####BBB##BBB################&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame9();
        }

        void frame9()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP55YYY5555YYY555YJJY55YJJJY55YJJJJ55YJ?JY5PGGGGGG\n"
                         "GGGGGGGGGGGGGGGBBBBBBBBBBBBBBBGGGGGGGPPPPPP5YYYY5YJ??777777?777!77777!!!7777!!!!777!!!7777?JYPBBBBBB\n"
                         "##########BBBBB###############BGP5JJJY5YJ??777!777!!!!!777!!!!77!!!!!777!!!!777!!!77!7!!!7?J5PBB####\n"
                         "##########################BBGGYJJ?77!!77!!!~!!7!!!!!7!!!!!!77!!!!777!!!!7777!!!7777!!!7777?J5GBBB###\n"
                         "#########################BPJJJJ???7777!~!!!!!!!!77!!!!!777!!!!777!!!!777!!!7777!!!77777!!7?JY5GBB###\n"
                         "#########################BPJ7?YY5YJ7!!7!!!!!!777!!!!777!!!777!!!!77777!!777!!!!777777777777!7?JPBB##\n"
                         "&&&&&&&&&&&&&&&&#########BP?7?Y5PGGP5J7!!!7!!!!!777!!!!7!!!!!777!!!!!777!!!777!!!!77777!7777??J5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&###BG5J??JPGBBGP5J?7!!!!!7!!!!77!!!!!!7!!!!77777!!77777!!777777!77777777?JPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&####B5J??JPP5JJJJ?7!!7!!!!!!77!!!!!7!!!!77777!!77777!!77777777777?JYYYJ??YPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&####BPY??????777JYY?7!!!77!!!!!777!!!777!!!!!7!!7!!777777777???JY555YJ?7?J5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&###BGPY???!!!!!7?YYJ7!!!!77???77!!!!!77!7!!!!!!!777777777??JYPP55Y?777???J5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&###BBPY?7!~~!!!77Y5J77!!!77?JY5P5J?7J5PYJ?7!!!77!!!!777??Y5555J?777?7777?JPBB#&\n"
                         "&&&&&&&&&&&&&&&&&&&&##BPJ??!~~~~~~~~!?JYJ??7!~!!??JJY5PPPYJYPGPJ7!!!!!!!!!777?JJ?7!!!!!!777??JYPB#&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&#GJ~~!!7!~~~!777??JYJ?7!!77??7!!?YYJ7!7J55J??????777??J?7!7???7777?JJY5GB#&&&&&\n"
                         "@@@@@@@@@@@&&&&&&&&&&&#BGGGGGGGPPGGGBBBBBBBGGPGGGGGGGGGBGGGGGBBBBGGBBBBGGGGBBGGGGBBBBGGGBB###&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&###&&&&&&&&&###&&&&###################################&&&&&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame10();
        }

        void frame10()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGBBBBBBBBBBBBBBBGGGGGGGGBBBBG5J?JYYYJ??77!!77777!!77!!!!7777!!!7777!!!777!!!77?JYPGBBBBBBBB\n"
                         "#####################BBBBGPPPY??J5GBBG57!!!77!!!!!77!!!!7!!!!!!!!!!!!!77!!!7!7!!!!777!!!?YPBB#######\n"
                         "####################BGP5JJ?77!!!7YGBBB57!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!77!!!7777!!!77?J5GGBB######\n"
                         "####################GPY?!!!77?JYPGB##B5?7!!!!!!~~!!!!!!!!!7!!!!!7!!!!!777!!!!77!!!777!!!7JYPGB######\n"
                         "&&&&&&&&&&&&&&######GP5J7!?Y5PGBB######BPY7!!!!!!!!!!!777!!!!!77!!!777!!!777!!!7777!!777777J5GB#####\n"
                         "&&&&&&&&&&&&&&&&####GP5?!!7JPBB########BG57!!!!!!!!7777!!!!!!!!!777!!!777!!!777!!!777!!77??YPGB#####\n"
                         "&&&&&&&&&&&&&&&&&&##GGPJ7!?YPGB#######BBB5?77!!77777!!!77!!!!777!!!777!!!7777!!7??7!7?JJ?77?5GB#####\n"
                         "&&&&&&&&&&&&&&&&&&&#BGPJ7!!7JYPGGBBBBGGGG5?!!!7?JY55JJ77!!77!!!!!77!!!777!!7?JJJJJYY5555J??J5GB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&##G5Y?!!!!7?5P5??JYP5?77!!!7?JY5P55Y?7!!!7!!!!777!!7?Y5555PPPPP5J??77??YGB####&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&##BGPYYJ7!~!!7!!!?Y5?!!!!!!!!!7?J5P55Y?!!!!77!!!7?Y555J?JY5YJ??77777?J5BB##&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&##BP5Y?!!~~~~~~!J5PY?7!~~!!!!!~!!7??J?7!!!!!!!777?777!!7777!!!7777??YPB#&&&&&\n"
                         "@@@@@@@@@@@@@&&&&&&&&&&&&BY~~~!!~~~~!!7?55Y?7!!!77!!!!77!!~!7!!!!7777!!7777!!7????777?JJ5PG##&&&&&&&\n"
                         "@@@@@@@@@@@@@@@@@&&&&&&&&#BP55PPP555PPGBB##BGPPPPGGP55PPPP5PPPPPPPPGGGPPPGGGPPGGBBGGGGBB###&&&&&&&&&\n";

            sleep(m_play_speed);
            frame11();
        }

        void frame11()
        {
            m_frame++;
            clearConsole();

            std::cout << "555555555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555PP555PP5555PPP55PPP5555P555555555555555PPGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5J??JJ????J??7??J?777?J?77????77???7777?7777????J5GBBBB\n"
                         "############BBBBBBBBBBBBBBBBBB#############BG5J?7!!!7!!!!!7!!!!!!!!!!!!!!!777!!!!!!!!!777777?JPGB###\n"
                         "############BBY?J5PPJ?J5GBB################BBPJ?7!!!!!!!!!!!!!!!!!!77!!!!777!!777!!!7777777?JYPBB###\n"
                         "#############GY?777??7J5GBBBB###############BGP5?777????77!!!!!!!777!!!777!!777!77777!!77?J5GBB#####\n"
                         "&&&&&&&&&&&##BY7777777?YGBB#################G5YJ7!!7JYYPPYJ7!!!77!!!777!!!777!!7777!777777?YGB######\n"
                         "&&&&&&&&&&&&&#BPY?!!77?YPGB##############BBBP?!!!7!7?JJJ5PPP5J?7!!77!!7777!!7777!!7777777?YPBB######\n"
                         "&&&&&&&&&&&&&&&##BG5J77!7J5PGBBBBBB#BGGGBBBBPJ7!!!!!77??7?JY55YJ?77!7777777777?J55J??JYJ??J5G#######\n"
                         "&&&&&&&&&&&&&&&&&&&#BBPJ?7!!?Y5PGGP5Y???JYPGPJ7!!!!!!!!!7777?7??77!!!7?JYYJ?J5PP5PGGPYY?77?5G####&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&##BG5J7!~!?J7~~!!7!!7J5?!!!!!!!!!!!!!!7777!!77!!7?JYYYYYYJ??JJJ???JJYPB###&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#BG5Y?7!!!!~~~~!7Y5Y?7!~!!!!!~!!!!~!!!!!!!777!!7??7!!7?7!!7??JJJ5G##&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&##G?~~!!~~~!!!7YP5J7!!!!!!!!!!!!!!!!!!!777!!777!!!7??7!77??YPG##&&&&&&&&\n"
                         "@@@@@@@@@@@@@@@@@@@&@&&&&&&&&&#GPPPGGPPPGGBB##BGPPPGGGPPPGGPPPGGGPPPGGGPPGGGGGGGBGGGGGB##&&&&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######&&&&&&&&&##########&&&&&########&&&#####&&&&&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame12();
        }

        void frame12()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGPPPPPP5YYY55YYYY55YJJY5YYJY55YJJY5YJJJYY5PPPP5PGGGGGBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5YJ?7777777!7777!!!!7!!!!77!!!!77!!77JJ???JY5PGBBB\n"
                         "#############BBBBBBBB########################BBBBPYJ?77!!!!!!!!!!!!!7!!!!77!!!!77!!!77!!!!7!77?YPBBB\n"
                         "############BPYY5GBB#########################BGYJ7!!7?J?!!!77!!!77!!!!7!!!!777!!!777!!777!!77?J5GBB#\n"
                         "############GY7!!7JYPGB######################BY7!!!7?J555Y?7!!77!!!777!!!77!!!7777!77777!!77777JPBB#\n"
                         "&&&&&&&&&&&#BG5YJ?!!!?YPGGBB#################BY77!!!!!7JY5P5Y?7!!!!!!!!7!!!!7777!777777777??JYPGGB##\n"
                         "&&&&&&&&&&&&##BBBBG5J7!!7?Y5PGBBBB####BBBBBBBG5?!!!!!!!!!7?YJ?7!77!!!!77!!!77!!!77777777?JY5GBB#####\n"
                         "&&&&&&&&&&&&&&&&&&###B5J7!!!7?Y5PPGGBG5YY5PGGG57!!!!!!!!!7?55J?7!!!777777??777?J?7?????77JPGB#######\n"
                         "&&&&&&&&&&&&&&&&&&&&&###BPY?7!!!7?YY?77!!!!?YP5?7!!~!!!!!!7???77777!!7JJYY5YYY5555YYYYJ?J5GB######&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&##GPJ7!~!!!~~~!!!!?Y5?7!!!!7!!!!!!!!!7!!!!!?JJ??JY5Y??JYYJ?????YGB###&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&###B57~~~~~^^~~~7YP5Y?!~!!!~~~~!!~~~~!!~!!!!!!!!!!!!!77!!7JGBB###&&&&&&&\n"
                         "&&&&&@@@@@@@@@@@@@@&&&&&&&&&&&&#PJ7?JJ?7??JYYPGG5J???JJ????JJ???JJ???JJJ??JJJ??JY5YJJYPB#&&&&&&&&&&&\n"
                         "@@@@@@@@@@@@@@@@@@&&&@@@&&&&&&&&&##################BBB#BBBBBBB######BB###B#############&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame13();
        }

        void frame13()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPGPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP5YJJJYYYJJJYYJJJJYJJ?JYYJ??JYYJJ5PPGGGGGGGGBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB#######BBBBBBBBBBG5?7!77!!!!77!!!!7!!!!!7!!!!7!!!!77JYPGGGBBBBBBBBBBBB\n"
                         "##################BB#BB######################BBGY?7!!!!7!!!!!!!!!!!77!!!!77!!!777!!7?J5PPPPPGGBBBBB#\n"
                         "############BBBGGBBBB##BB###################BPJ7!!!7JYJ77777!!!!!!!!!77!!7!777!!7777!77?JJJJJJ5PGBB#\n"
                         "&&&&&&&&&&#BGPY7!7?YPGBBB###################BP?77!!7YPPP5J77!!!!!!!!777!!!777!!7777!7777777?JJ??J5G#\n"
                         "&&&&&&&&&&#GJ!!7??!!!7J5PP5YYPGBBB########BBB57!!!7?Y5PGPJ!!!77!!!77!!!!77!!!7777!77777777777?J5PG##\n"
                         "&&&&&&&&&&&#BGPGBBG5J777777!!!7?YPGBBBGGBBBBG5?7!!!!7?YPP5J?7!!77!!!!77!!!7777!777777777?7?J5PGB####\n"
                         "&&&&&&&&&&&&&&&&&&&##BG5JJY55J77!!?Y5J77?YPGG5?!!!!!!!77?JJJ?7777!!!!77!77777!7777777777??J5GB######\n"
                         "&&&&&&&&&&&&&&&&&&&&##########B5?!!~~~!!!~!?5Y7!!!!!!77???YJ?777777?777???777??777???777?Y5PB###&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&##B57~~~!~~~~!7?5Y?7!!~!!77!77??7!!!7?Y5YYY5555YJYPP5J777?J5PBB###&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BY!~!!!~~~!!7?55J7!!!!!!!!!!!!~!!7!!7?Y5Y???YYJ??YP5J??5GB##&&&&&&&&&&\n"
                         "@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&BGGGGGPPPGGGB###BGPPPPPPPPPPPPPPGGPPPGGGGPGGBGPPPGBGGGB##&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame14();
        }

        void frame14()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5P5555PP5555P55555P55555PP5PPPGGGGGGGGGGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBGBBBBG5YJ????J?777???777??7777??7777?JJYPGGGGBBBBBBBBBBBBB\n"
                         "##########B#################B#############BBBBBPJ7!!!!!!!!77!!!!!!!!!!!!!!!777!!7?J5PGGBBBBBBB######\n"
                         "############BB######BB#####BBBBB############BGP5?7!777!!777!!!!!!!!!7!!!!777!!!777!7?Y5PGGBBBBB#####\n"
                         "############B#GYYPGBB#########BB############GY77777J55J?7!!!77!!!7777!!777!!777!!!7???JYYY5555PGBB##\n"
                         "&&&&&&&&&&#G5Y?!!!7JYPPP5PGGBB##B#########BBGY?7??JYP5??7777!!!777!!77!!!!777!77777777??????JYY5PB##\n"
                         "&&&&&&&&&&#PJ!!7??7!!7????7??YPGBB##BBBBBBPJ?7!!!7?Y5PP5Y77!77!!!!77!!!777!!!7777777777777??JYPBB###\n"
                         "&&&&&&&&&&&&#BP555PG5J??JJ?7!!!7J5PBBPPPGGPJ7!!!!!7?JY5P5J777!!!!77777!7777777777777777777???YPB####\n"
                         "&&&&&&&&&&&&&&&&#####BBBGGGGPY?7~!?JJ7!!7JJ7777!!!!7??JJJ?7777777!!!777777777!!7777777?777?Y5PB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&###GY7!!~~~!!!~~!77!!!!!!!7?JJ?7!777!!!777!77?77!777777??777?J5PB####&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BJ!~~~~~~~~~!77?77!~!!!777??7!~!!??77?JYJ?7JYYJ?????77?YPPB####&&&&&&&\n"
                         "&&@@@@&&@@&&&&&&&&&&&&&&&&&&&#BJ!!777!!77??YPPY?7!777777777!!7?JJJJ5PG5YY5GP5YYJJ???YGB#&&&&&&&&&&&&\n"
                         "@@@@@@@@@@@@@@@@@@&@&@&&&&&&&&&#BBBBBBGBBBB####BBGGGGGGGGGGGGGBBBBBBB##BB###BBBBBGGBB##&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame15();
        }

        void frame15()
        {
            m_frame++;
            clearConsole();

            std::cout << "55PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555PPP5PPPPPPPPPPPPPGGGGGGGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGBBBGGGGGGGGGGGGBBBBBBBBBBBBBBBGGPP55YJJJJJJJJ?JJJJJJJJJYYYY5PPGBBBBBBBBBBBBB\n"
                         "#########################BBGPPPPPGGPGGGPPPBBBBBBBBB##BGPJJ?????J???????????????JJJJJJY5PBBBB####BBBB\n"
                         "######################BGPYJJJJJ??JJY55555555PGBBBGPP5J?????????J???JJ???JJ????JJJJJJJJ5GBBBB########\n"
                         "#####################B5JJJYJ???JJ???JJYPGPPPPGGP5YJ????J???J????JJ????JJ???JJJ???JJJ?JJY5GBBB#######\n"
                         "&&&&&&&&&&&&&&&&&###&#BBGBBBGGGGBBGPYJ?JJYY5555J????JY5YJJ???JJJ???JJ????JJ????JJ??JJJ???JY5GGB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BBPY????JYYYJJJ?J5P5JJJ??????JJJ??JJJJ?JJJJJ??J?JJ??JJJJJJYPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GY?????JJJJ???JY5PYYJJJ?JJ?????JJ????JJ??JJJJ???JJJ??JJJJ?JPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BPYJ????JJ????????JYYJ???JJ??JJJ???JJJJJJJJ?JJJJJJ??JJJ?JY5PG##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BPYJJ??????????????JJ55YJJ?????JJ??JJJJ??JJ??JJJJJ??JJJJY5GB####&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&GY?777777777?777??77?JJ?7???????????????J????????????J5PGB###&&&&\n"
                         "@@@&&&&&@@&&&&&@&@@@@@@@@@@&&&&&&&&BYJJYYJJJJYYYYY55YYYY5YYYY55YYY555Y5PPPPPPP55YY55P5YY5PB#&&&&&&&&\n"
                         "&&&&&&&&&&@@@@&@@@@@@@@@@@@&&&&&&&&&&#####################################################&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame16();
        }

        void frame16()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPPPPPPPPP5YYY5555YYY5PPPPPPPPPPGGGGBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP5YJJJYYJ????J???JJ???JYYYJJJJ5PGGGGBBBBBBBBBBBBBBBBB\n"
                         "############################################BGY?????????J????JJJ???JJJ????J??JJY55PGGBBBBB#######BBB\n"
                         "#########################################BBBBG5JJ????JJ????JJ????JJ???JJJ????JJJ??JJ5PBB############\n"
                         "#########################################BGP5Y????JJ????JJ????JJ????JJJ???JJJ??JJJJJ?YPBB###########\n"
                         "&&&&&&&&&&&#####&&&&&&&#&&&&#############BGY?77?JJ????J???JJJJ???JJ????JJJ???JJJ???JJYPGBB##########\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###########BGYJ?????JJ?????J????JJJJ?JJJJ???JJJJ??JJJ???JY5GBB########\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BGY?77????????????JJ????JJJ???JJJJ???JJJJJJJJ???JJ5PGB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&########BP5Y?????Y5P5JJ??JJJJ??JJJ?????J???JJJ???JJJJJ??JJJ??J5GB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####BGPPY??????7?J5PGGG5YJ????JJJ??JJJJJJJJJJ??JJJJ??JJJ???JY5PGB#&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BP55J7?????777???7?JPPY???J????JJJ???JJJJ?JJJJ???JJJ???JY5GBB###&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&GY?77777!!777?7777777?YPGP5YJ???????????????????77???????J5GB###&&&&&&\n"
                         "@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&B5YY555YYY555555PP55Y5PGB##BGPP5555P5555PPP555PP555PPPP55PGB#&&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######################&&&&##############################&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame17();
        }

        void frame17()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555PPPP555PPPPPPGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBGGP55YYJJJJJYYYYYY55PPGGGGGGGGBBBBBBBBBBBBBBBBBBBB\n"
                         "B##########B#BBBBBBBBBBBBBBBBBBBB#B##B#######B#BBBG5JJ??????J????JJYJJJY5555555PGGGBBBBBBBBBB#####BB\n"
                         "#############################################BBG5YYJ????JJ????JJ?????JJJJJJJJYYYYY5PGBBBBBBBB#######\n"
                         "#############################################BBG5JJJJJ?????JJ?????????JJJJJJ??JJYYY5GGGGGBBBB#######\n"
                         "############################################BGGPYJJJ?????JJ????????????????JJJJ???JYPP5YY5PGBB######\n"
                         "&&&&#####################################BBBPJJ????????????JJ?????JJJ???JJJ???JJJ???JJJJJJJJY5GB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&#################G5YJ?????J?????????????JJ???JJJJ???JJJ???JJJ???JJJJJ?JY5G##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########BGPYJ??????????????????????JJ???JJJ????JJJJJJJJJJ???JJYYPB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BGP5JJ???????J??JJ?JJJ???JJJ???????????JJ???JJJJ???JJJYYY5G##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BPY?????????????JJJJ????JJJJ??JJJJJJJJJJ???JJJ???JJJ???J5PGB##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BGBBBGPYJJ?77??J5PP5YJ??????????JJJ???JJJJ?JJJJJ???JJJ???JJY5GB###&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&B5YYYJJJ???77??777??JJY5PP55Y???????????????????????????????JYPGB###&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&B5Y5P5YJ??JJYYJJYYYJJ?J5GB##BGPYYJJJYYJJJYY5YYJJYYYJJJYYYYJJYPG##&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######B###BB####B#############BB###BB#######################&&&&&&&&\n";

            sleep(m_play_speed);
            frame18();
        }

        void frame18()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBGGGPPPPPPPPGGGGGGGGGGGGBBBBBBBBBGGGGBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5YJJJJYPPGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "##########################BBBBBB#BBB#####BBBBG5J7??JJ??JYY5PPGPPPPGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "##########################################BBBBPYJJ????JJJJ?JJY5YJJJJ5PPGGGGPGGBBBBBBBBBBBBBBBBBB####\n"
                         "##########################################BGGPY???J??????JJJJ?????????JY55YJJY5PPGBGGPPGGBGPPPGGB###\n"
                         "#########################################BPY???????????J????JJJ?????JJJ???JJJJ??JJY5YJJJY55YJ?J5PB##\n"
                         "##########################################G5J??7?JJJ????JJJ???J??JJ????JJJ???JJJJ????JJJ???JJJY5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&####################BGPJ?????????JJ????JJJ????JJJJJ??JJJJ????JJJ????JJJJ??J5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&#&&&##########BG5JJ?????????????J??????JJJ????JJJJ????JJJ???JJJJ??JJYY5PGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BG5J?????J??????JJ?????????????????JJJ????JJJJJ??JJJY5GBB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BPY????????????JJ??JJJJJ?JJJJ???JJJJJ??JJJJ???JJJJ??JYPB#####&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BGY?????????????JJ???JJJJ??JJJJJJ?JJJJJ???JJJJJ??JJJJ5PB##&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GP55PGBG5YJJ??????JJJJ?????????????????????????????????????JJY5GB#&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&GJ7!?YPP5J?JJJJJY55555YYYYYJ????JJJ????JJJ???JJJJ???JJJJ??JJYYYPB#&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BBGBBBBBBBBBBBBBBB#######BBGGGGGBGGGGBBBBBGGBBBBGBBBBBBGGBB###&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########&#####&&&####&&########&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame19();
        }

        void frame19()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBB\n"
                         "GGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "#####################################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGGBBBBBBBBB\n"
                         "######################################BBBGGGGGGBGGBBBBBBBBBBBBGGGGBBGGGGGBBBBBBBBBGGPP5JJJYPGB##BBB#\n"
                         "#######################################GP5JJ?J5PPPPPGGGGGGGGP5YJJJY55YJJY5PGGBGGGP5YJ?JJJY5PBB######\n"
                         "#####################################BPJ???????JJYYYYJJJY5YJJ??JJ????JJJ???JJY5YJJJJJJJ??JY5PGBB####\n"
                         "#####################################BPJ???????J?????JJ????JJJ????JJJ????JJ?????JJJ????JJJJ??JYPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&#################G5????J????????????JJJ????JJJ???JJJ????JJJ????JJJJ???JY55PG####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########BPJJ?77?????????JJJ????JJ?????JJ????JJJ???JJJJJ??JJYY5GB#######\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######B5????????7??JJ???J??????????????JJJJ???JJJJ??JJJ???JYPBB####&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######B5JJ?777????????JJ?????JJ?????JJJ???JJJ????JJJJ??JJYY5PB###&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####B5??777777777????????????????????????????????????J???JY5GB#&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#G55YJJJJYYJJJJJYYJJJJYYYJJJJYYYYJJJYYYJJJYYYYJJJY5YYJY5PG#&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####BBBBB##BBBBBBBBBBBBBBBBB####BBBB##BBB#####BB#########&&&&&\n";

            sleep(m_play_speed);
            frame20();
        }

        void frame20()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "###B###B###BBBBBBBBBBBBBBB##B#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "##########################################BBBB##BBB#BBBB#####BB#BBBBBBBBBBB#B########BBBBBBBB####BBB\n"
                         "###############################################################BBB#BBBBBBBBBBBBBBBBBBBGPPGGBBB######\n"
                         "#############################################################BBBBBBBBBBBBBBBBBBBBBGPP5YJJJYPGGBB####\n"
                         "############################################################BBBBBGPPPGGGGPPGGGGPP5YJ?JJJJJJJY5GB####\n"
                         "#&&&&####&#######################################BBBBBBBGGGGGGP55YJJJJY5YJJJY5YJJ??JJJJ??JJYYPGB####\n"
                         "&&&&&&&&&&&&#&&&&&&&&&&&&&&&&###############BBGGGGGGGPP5YYYYYYJ??JJJJ????JJJ???JJJ?????JJJ??JYGB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########BGP5YYJJY55YJJJJJ??7??JJJ?7??JJ????JJJ????JJJJ???JY5PGB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######GP5YJ???JJJJ???JJJ????JJJ????JJ?????JJJ???JJJ???JJJJ??J5G###&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####G5J??JJJ?77?JJJ????JJ?????JJJ????JJJ????JJJ????JJ????JY5PB##&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####B5J7777777777777?????7????????????7?????777?????777????J5GB#&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##PYYYYYYYJJYYYYYYJY5YYJJYYYYYJJYY55YYJYY5YYJYY555YYY5PPPGB##&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&################BBB#######BB#############B##############&&&&&&\n";

            sleep(m_play_speed);
            frame21();
        }

        void frame21()
        {
            m_frame++;
            clearConsole();

            std::cout << "555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBB##########BBBBBBBBBBBBBBBB##B#BBBBBBBBBB################################\n"
                         "####################################################################################################\n"
                         "###############################################################################BBBBBBBB#############\n"
                         "###########################################################################BBBBBBBGPGGBB############\n"
                         "###################################################################BBB#BBBBBBBGGP5Y??J5GBB##########\n"
                         "##################&&&&&&&&&&&&&&&&&&&#####################BBBBBBGP5PPGPP5PGGP5YJ???JJY5GB#######&##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########BBBBBBGP5PGGP5YJ???JJJ??JJYJ????JJJ??J5GBB###&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&############BGP5YJJ??JJJ?7?J?????JJ????JJ??J?JJJJJYPB#&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&BGGGB##G5PBBBGP5YJJ???????7???????????????????JJ????JJ5GB###&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#577J5GPJ7?5G5?7?????7???77???????JJ????J????JJJ???JJJJYPB#&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BBBB#BBBB##BGGBBBBGGGBBGGGGGGGGGBBBBBBBBBGBBBBBBGBBB#####&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########################&&#&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame22();
        }

        void frame22()
        {
            m_frame++;
            clearConsole();

            std::cout << "GPPPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "#########BBBBBB##B##############BBBBBBBBBB#B########################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&########################&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&#&#&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame23();
        }

        void frame23()
        {
            m_frame++;
            clearConsole();

            std::cout << "GPPPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "#########BBBBBB##B##############BBBBBBBBBB#B########################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&########################&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&#&#&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame24();
        }

        void frame24()
        {
            m_frame++;
            clearConsole();

            std::cout << "7777????JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJYYYYYYYYYYYYYYYYYYYYYY5555555555555555555555555555555555\n"
                         "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBGGGGGGGGGGGGBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "###############################BBBBBBBB#############################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "####&&&&&&&#########################BBBBBBBBBGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB#######\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBGGGBBBGGGGGBGGBBB##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####BBGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBB##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&########################################################&&&&\n";

            sleep(m_play_speed);
            frame25();
        }

        void frame25()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "##############B#############BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "####################################################################################################\n"
                         "####################################################################################################\n"
                         "########################################BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB#############B##############\n"
                         "#################################BBBBBBBBBBBGBBBBBBBBBBBBBBBBBBBBGGGGGGGBBBGBBBBBBBBBBBBBBBB########\n"
                         "################################BBBGPPPGGPPPPPGGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGPPPPPGGPPPPPGGBB#####\n"
                         "###############################BP5Y?!!7?J?7!7?JJ?7!?JYY?77?YY?777?JJ?77?JYJ???JYJ???JJYJ?7?JYPGBB###\n"
                         "&&&&&&&&&&&&&&&&##############B57~~~~~~~~~~~~~~!~!!!!~!!!~~!!!!!!~~!77!!!!!!!!!!!!!!!!!77777!7J5B###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&###BPY?!~~~~~^~~~~~~~~~~~~~~~~!~~~~~~~~~~!!~~~~!~!!!~~~!!!!!!!!!!!7J5B###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BBP5J?77!!777!!7777!!77777!!!77777777777777777!!77777!77??7!!?YP###&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BGGGPPPGPPPPPGGGGGPGGPPPPPGGGGGGGGGPPGGGGGPPGGGGPPPGGGGPPPGB##&&\n";

            sleep(m_play_speed);
            frame26();
        }

        void frame26()
        {
            m_frame++;
            clearConsole();

            std::cout << "5555555555555PPPPPPPP55PPPPPPP5555PPPPPPP555555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP\n"
                         "PPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPPPPGGGPPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP5555PPPPPPPPGGGGPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBB\n"
                         "###BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGY7!!7?JYJJJJY555YYY55P5YYY555YYY5P5YY55P5YYY555YYYY555YJY5PGBBBBB\n"
                         "####################BBBBBB####BBBBG5?77!!!7??7777??77!7???7!7??77777???77????77????777???777?J5PGBBB\n"
                         "###############################BGP5J7!!!77!!!!777!!777777777777!!77777777777777??777??77777???J5GBB#\n"
                         "##############################BB5?7??J?!!!!!!!!!!!!!777?J?7!!77!!!!!77!!!!77777?JJ?77!77777??J5PBB##\n"
                         "###############################BPY?J?7!!!!~~~!!!!!~!!777??J??7!!!!!!!!!7!!!7?JJJJ??777!!77???JJ5GB##\n"
                         "&#&&&&&&&&&&&&&################BPJ77??77!!~~~!!!~~!!!!7??J??777!!!!!!!!!!!!7??JJJJ?77!77777?Y5PGB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&##########BBG5J????7!!!~!!~!!!!!77?JYYJ7!!!!!!!!!!!!77?Y5YJ?777777777?YPBB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&########BG5Y?7!~!!~~!!!!!!?Y5PP5J77!!!!!!!!!!!!7?5PPP5J?77!!777?YPB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BBGY?!~~~~!!!!~!7JY5PPY7!!!!!!!!!!!!7?JY55YJ?77777777?YGB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###GY?!!~~~~~~~~~~~~!!!777!~~~!!~!~~~~!!!7?J?7!!!!!!!!!!?YG#####&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GP5YYY?77??JJ???JYYYJJJJJ?????J????JJJ?JYYYJ?7?JJJ?7?J5B##&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BBBBBBBBBBBB####BBBBBBBBBBBBBBBBBBBB#BBGBBBBBBBBB##&&&&&\n";

            sleep(m_play_speed);
            frame27();
        }

        void frame27()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPPP55YYYY5555555PPPPPPPPPPGPPPPPGPPPPPPGGGPPPPP5555555YYY55PPGGGBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBPJ7777777777?JJYYYY5555555555YYYY55YYYYYY555YYYYYJ?7777?J?777?YGBBB\n"
                         "#######BB################B#BBBBBBG5?7!!~!777!!!!7????777JJJ?777?JJ?777?J??77??JJ?7777777!!777?Y5GBBB\n"
                         "################################BGY7777!!!~!!!!!!~!7777!~!!!7!!!!!!77!!!!!777777777!!!!7777!!7J5GBBB\n"
                         "################################BG5?7!!!!!!!!~~!!!!!!77777!~!!!!!!!!!!77!!!!77??7????7!!!!77??J5GBB#\n"
                         "################################BG5?777!!~~!!!!!!~!!77??Y5YJ?7!!!7777!!!!77?JY5P5YJ?77777!!!7?JYGBB#\n"
                         "&&&#&&&##########################BPY?7!!!!!!!!!!!!!7?Y55PPY?7777!!!!!!77!!!7?YPGGGP5J?7!!7777JY5GBB#\n"
                         "&&&&&&&&&&&&&&&&&&################BBGPJ7!!~!!!!!!!!7?YPPGG5J?7!!!!!!!!!!7777?YPGGG5J?777777??JYPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&##############BBP?!!!!!!!!!!!!!?YPPGPY?77!!!!!!!!!7!!!7?YPGGGPYJ?77777??JYPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&########BBPJ7!~~~~!!!!!!!?Y5PPP5J77!!!!!!!!!!!77?JYPPPP5J?77777!!7?JPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BP?!!!!!!!!!!!!!777?Y5Y?7!!!!!!!!!!7!!!7?J5YJJ?7777!77777?Y5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BBBGY?!~~~~!!!!!!!!77!!!!!!!!!!!!!!!!!!!77!!7????77777?7777?JPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BG5?77!!!~~~~~~~~~~~~!!!!~!~~~~~!!!!!!!!!!!!!!!!!!!!!!!!!!!!7J5B###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###B5?!!777!~!!!77!!!!7777!!7777!!77777!!!77?77!77777!!!7777!!7?YG###&\n"
                         "&&&&&&&&&@@@@@@&&&&&&&&&&&&&&&&###BBGGGBBGPPPPGGGPPPGGGGGPPPGGGPGGGGGGGGGGGGGGGGGGGPPPPGGGPPPGGB##&&\n";

            sleep(m_play_speed);
            frame28();
        }

        void frame28()
        {
            m_frame++;
            clearConsole();

            std::cout << "Y555555555555555555PPPPPPPPPPPPPPPPPPPPPPP5555555555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGPPP\n"
                         "PPPPGGGPPPPPPPGGGGGGGGGGGGGGGGGGGGGGGGGGGP5YYYY55YYY555PPPGGGGGGGGGGGGGGGGGGGGGGP5YYYYYYYJ?J5GGBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ7777777!!!77JY5PGGGPPPPGPP55PPPP55PPPPYJ?7!!777?J5GBBBBBB\n"
                         "BB########################BBB####BBBBBBBGP?!!!!!!!!!!!!!!7?JYJ?77?YY?77?JJ?777?YY?77777!!!7J5GBBBBBB\n"
                         "######################################BBBPJ!!~!!!!!!!!7777!!!!!!!~!!!7!!!!!!77!!77777!!777?Y5GBB####\n"
                         "########################################BP?!~!!!~~!!!!7?YP5J?7!!!!!7!!!!!!!!!77??J5P5J?7!!7J5GB#####\n"
                         "########################################BGJ7!~~~!!!!!!7?YPPGG5J?!!!777!!!!!77?J5PGGPY?777?JYPGBBBB##\n"
                         "#&#&&&&&&&&&&&##########################BP?!!!!!!!!!!77J5PPGPY?7777!!!!!77!!!7J5GGGP5J?7!!7?Y5PGBBB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&################BPJ7!!~~!77!!!!7YPGGG5J?7!!!!77!!!!77?YPGGG5J7777??77?JPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&#############BP?!~!!!!!!!!!7JYPGGPJ7!!!7!!!!!777!!7?5PGGP5J?77!77?J5PBB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BBPY?7!~~~!!!!~!7?Y5PP5J77!~!!77!!!!7?JY5555Y?7!!7777!7?5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BBP?!~~!!!!~~!777!!7?J?!!!!77!!!!777!!!7JJ?7777?77!77?JYPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####BGP5Y?7!~~~!!!~~~!77!!~!!!!~~~!777!~!777!!!777!!!!7?77!7?5G###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###GJ!~~~~~~~~~~~~~~~~~~~~!~~~~~!!~~~~~!!~~~!!!!!!!!!!!!!!7JPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###B5YY555JJJJY5YJJJY55YJJY55YYYY55YYYYY55YYYY555YYY555YJJYPG##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########################################################&&&\n";

            sleep(m_play_speed);
            frame29();
        }

        void frame29()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP555YYY555PPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPPP5YYYJJJYY5PPGGGGGBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP5J7!!7777777?Y5PPGGGGGGGGP555PPP5555PPP555PPP55YJ7!!77?77!7?Y5PGBBBB\n"
                         "###########################BBG5J??77!!!!!!!!!!!?JY5PPP55Y?!!7?J?7!!7?J?7!!7JJ?7!!7777!!!77?J?JYPBBBB\n"
                         "#############################BGPY?!!!!!!!!~!!!!!!!7JYJ7!!!!7!~!!!77!!!!777!!!!777!!!!777!!7?YPGBBBB#\n"
                         "#############################BBBG5J7!!~~~!!!!~!!!!7!!!!77!!!!!77!!!!77!!!!777!!!!777!!!!7?JYPBB#####\n"
                         "################################B5?7!!!!!!~!!!!!!!!??7!!7777!!!!!77!!!!7777!!7JJ?7!!777!!!7J5BB#####\n"
                         "&&&&&&&&&########################GP5J!~~~!!!!~~!!7?Y5P5YJ7!!!!!!!!!!777!!!7JY5PP5Y?7!!!7?JYPGBB#####\n"
                         "&&&&&&&&&&&&&&&&###################BGJ7!!~~~!7!!~!7J5PGGPY?7!!!!!7!!!!!77?Y5GGGPJ7!!7??JYPPGBBB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&###########BP?!~~!!!!!!!!7?Y5PGG5?7!!!7!!!!!77!!!7?5GGGG5J?77!!7?J5PGB######\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BGY?7!~~~!!!!~!!?5PGGPY?7!!~!!77!!!!7??Y5PGGPJ7!!7777!!7JPB######\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BBP?!~~!!!!~~!!77Y5PPP5J7!!!7!!!!!77!!!7?YPPP5YJ?77!!77?J5PB####&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####BBP5J?7!~~~!!!!~~!7?JJJJJ?7!~~!!77!!~!77??JJJJJ?7!!7??7!!7JPB####&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###GJ!~~~~~~~~~~~~~~!!~~~!!!!~~~!!~~~~~!!~~~!!77!~~!!!!!!!!7?5G####&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###G5YJY5YJ???JYJJ??JYYJ???JYJJ?JJJYJ??JJYYJ???JYYJ??JYYJ???YPB##&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BBBBB###BBBB#BBBBBBBBBBBB#B###########B#BBBBBBBBB#####&&&&&&\n";

            sleep(m_play_speed);
            frame30();
        }

        void frame30()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP55JJJJY5PPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPPPYJJ??7??JY5GBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5J777777!!!7?Y5PPGGGGGGGGGPPPPPPPPP55PPPPPPPPPPPP5YJ?!!!7?77!!7?5GBBB\n"
                         "#####################BBBBBBBBBGPY?7!!!!!!!!!!!?JY5PPPPPP5J7!7?YYJ777?JYJ?77?JYY?7!!777!!!!77??J5PBBB\n"
                         "############################BBG5J77!!!!~~!!!!!!!!7?JYJ?7777!!!!!!77!!!!77777!!!!77!!!!!777!!!7J5GBBB\n"
                         "#############################BBGY?7!!~~!!!!~!!!!!!!!7777!!!!!!!!!!!77!!!!!77777!!!777!!!!!77?JY5GB##\n"
                         "##############################BBBGG5?7!!~!!!!!!!!77777?Y5Y?7!!!77!!!!!!!77777?????7!77777!!!7?J5GB##\n"
                         "###############################BBBG577!!!!!!!!!!77?J5PPP5J??77!!!!!!!!!!!!77?JY5PP5J?7!!!777?JYPBB##\n"
                         "&&&&&&&&&&&&#####################BB5?7!!!!!!!!!!!7?J5GGGPY?7!!!77!!!!!77777?Y5GGGPY?77777?J5PGGBBB##\n"
                         "&&&&&&&&&&&&&&&&&&###############BBP?7!!!~!!!!!!!!7J5PGGP5J?77!!!!!7!!!!!77?YPGGGPY?77!77?JYPGGBB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&########BP?!~~!!!!!!!!!7?Y5PGGPY?7!!!!7!!!!!!7!!77J5PGGPYJ?7777!!7?J5GB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BP?!!!!~~!!!!!!!7J5PGGP5?77!!!!!!77!!!!77?Y5PGGPY?777777777?YPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&######BBP?!~~~!!!!!!!!!?Y5PPGPY7!!!!!!!!!!!!!!!77?Y5555YJ??77!!77?J5GB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&####BG5J77!!~~~~!!!~~~~!7?JY5Y??7!~~~!!7!!~!!77?JJJJ?77!!!!777!!7?YGB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BP?!~!!!~~~~!!~~~~!!!!~~~!!!~~~~!!!!~~~!!!!~~~!!7!!~~!!!!!!!!7J5B###&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GP55PPP5YYY55P55YY5555YYYY555YYYY555YYY55555YYY5P55YYY5PP5YYY5G##&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&############################################################&&&&\n";

            sleep(m_play_speed);
            handleTwoBlinks();
        }

        void frame31()
        {
            // start of blink
            m_frame++;
            clearConsole();

            std::cout << "5555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555555555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555PPPPPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP55JJJY55PPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP5YYJ????JY5GBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBPJ777!7!!!7?J5PPGGGGGGGGP55PPPP555PPPP55PPPP5YJ?!!!777!!!?5GBBBBB\n"
                         "###########################BBBBBBBBPY?7!!!!!!!!!!7JY5PPP55Y7!!7JJ?7!7?JJ?7!7?JJ7!!!77!!!!77?J5GBBBBB\n"
                         "#################################BBPJ7!!7!!~~!!77!!!7?J?7!!!77!~!!777!!!!777!!!!77!!!!777!!7?YGB####\n"
                         "##################################BBPY?7~~!!!!!!!!!7!!!!7?7!~!!!7!!!!777!!!77?7!!!777!!!!7?JY5GB####\n"
                         "##################################BBBBG5?7!!~~!!!!!!!7??J55Y?7!!!!!7!!!!!7?JY555Y?7!!777!!!7J5GB####\n"
                         "#######&&&&&########################BBGY!!~!!!!~!!77?J5PPPY?7!!77!!!!!77!!!7J5PGG5Y?7!!!7?JY5GB#####\n"
                         "&&&&&&&&&&&&&&&####&&&&###############B5?7!~~~!77!!!!?5PGGPYJ7!!!!777!!!77?JYPGGPY?!!7??J5PGGBB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&#############BGY!!~!!!!!!!!!7J5PGGPJ777777!!!!77!!!7J5GGGPY?77!!7?Y5PGB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BG5?7!~~~~!!!!!7?5PGGPY?7!!!!!!!!!!!7??Y5GGPY?7!7777!!7JPB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BGY!~~!!!!~~!!77Y5PGP5?!!!!!!!~!!77!!!7J5PPP5YJ?7!!77?J5PB####&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####BG5?7!~~~~!7!~~!7JY5P5Y?7!~~!!77!~~!77???JJJ?7!!7777!!7JPB###&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BP?!!~~~~~~~~~~~~~!~!!77!!~~~!~~~~~~!!~~~!!7!!!!!!!!!!!!?5G###&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BPYJYYYJ777?JJ????JJJ???JJJ????JJ????JJJ???JJJJ??JJYJ???J5B##&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB####&&&&&\n";

            sleep(m_play_speed);
        }

        void frame32()
        {
            m_frame++;
            clearConsole();

            std::cout << "555555555555555555555555555555555555555555555555555555555555555555555P5555PPPPPPPPPPPPPPPPPPPPPPPPPP\n"
                         "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555555PPPPPPPPPPPPPGGGGGGGGGGGGGGGGGGGGGGGGGGPPP55YJYY5PPGGGGGGG\n"
                         "GGBBBBBGGGBBBBBBBBBBBBBBBBBBBGP5YJJ?777?JY5PPPGGGGGGGGGGGGGGGGGGGPPPGGGGPPPGGGPPP5J?777!!777JYPGBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ7!!!77!!!!!7?Y5PPGGGGGGP5JJJY555JJJY55YYJJY555YJ?77!!!!777!!7J5GBBBB\n"
                         "######################BBBBBBBGPYJ?7!!~~!!!!!!!7?JY555YJJ?!!!!7??!!!!7??7!!!7??7!!!!77!!!!!7?JYPGBBBB\n"
                         "############################BBPY7!!!7!!~~~!777!!!!???!!!!!77!~~!!777!!!!7?7!!!!777!~~!777!!!7J5GBB##\n"
                         "############################BBBG5Y?!~~!!!!!~!!!777!!!7777!~~!777!!!!777!!!!7777!!!777!!!!7?JY5PGB###\n"
                         "#############################BBBBBPY?7!~~~!7!!!!!7?J?!!!7??7!!!!777!!~!77?7!!!!7?7!!!!777!!!7JPBB###\n"
                         "&&&&&&#########################BBGY7~~~!7!!~~!!7?JYP55YJ7!!!!77!!~!!777!!!7?JJ77!7??7!!!7?JY5PGBB###\n"
                         "&&&&&&&&&&&&&&###################BPJ77!~~~!77!!~!7JPPGGP5YJ7!!!!777!!!!7??YPPPP5J?7!!7??JY5PGBBB####\n"
                         "&&&&&&&&&&&&&&&&&&##############BGY7!~~!!!!!!!!!7?YPGGGGP5YJ?77!!!!!777?JJY5PGGGG5J?77!!7?J5PGBB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&#&######BBPJ7!!~~~!!!!!~!7J5PGGGPYJ?!!!!!!!!!!!?JYY5PGGG5J77!7777!!!7YPB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&######BGY7!~!!!!!~~!!77?Y55555J7!!!!!!~~!!777!!!?J55PPP5J?77!!77??J5GB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&####BBBPJ7!~~~~~!!!!!!7JY?7!77777!~~!77!!!!!7777777JYJ?7777777!!7?YGB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BGY?7!~~~~~~~~~~~~~~~!!~~!!!!!~~!~~!!!!!!!~!!!!!!!!!!!!!!!!!!7J5GB###&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#B5?7???7!~!!!77!!!!7777!!!7777!!77??7!!!7?77!!!7??7!!!7??77!!7JPB###&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BBBBBBGGPPPPGGGGPPGGGGGGGGGGGGPPGGGGGPPGGGGGGGGGGGGPPGGGGGGPGGB##&&&&\n";

            sleep(m_play_speed);
        }

        void frame33()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGGGPPP5YYYYY5PPGGGGG\n"
                         "GGGGGGGGGGGGGGGGGBBBBBBBBBBBBGGGGPYYJJ?777?JY5PPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP5YJ?777!777?Y5GGBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5?!!!!77!!!!!?JY5PPGGGGPPYJ?JY55YJJJY555YJJY555J??7!!!!777!!7?YPGBB\n"
                         "##########################BBBBBBGPYJ?7!!~~!!!!!!!7?J5P5YJ?7!!!!7?7!!!!7??77!!7?77!!!!77!!!!!7?J5PGBB\n"
                         "###############################BBPY7!!!!!!~~~!77!!!!!??7!!~!77!~~~!777!!!!777!!!!777!!!!777!!7?YPBBB\n"
                         "###############################BBBGP5J7~~~!!!!!!!!77!!!!7?7!~~!!77!!!!777!!!77??7!!!777!!!!7?JY5GBB#\n"
                         "################################BBBBG5J77!!~~!!!!!!!7??7!!!7?77!!!!777!!!!77?7!!7??77!!!77!!!7?5GB##\n"
                         "&&&&&&&&&&#########################BGY7!~~!7!!!!!7??777?JYJ7!!!77!!!!!777!!!7Y5Y?777??7777?J5PGGBB##\n"
                         "&&&&&&&&&&&&&&&&&##################BG5?77!~~~!77?77?JY5PPGG5YJ7!!!!777!!!7?JYPGGGP5J77!77?JYPGGBB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&#&&&##########BG57!~~!!!!~~!7?JY5PGGGP55Y?777!!~!!77??JJ5GGGGPYJ?77!!!7?JYPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BB5?7!!~~~!!!7777??JY55YJ?7!!!!!!7!!!!!7?J5P55YJ?77!!777777J5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BB5?!~~~!!!!!!!7777777??77!!!!!!!!!!777777?????777?777!!7?JYPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BP5J?!!!~~~~!!!~~~!!7!!77777!~~~!!7!~~!!7777!!!77!!!!!777!!7J5G###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#B5?!!!!!~~~~~~~~~~!!!!~~!!!!!~~!!!!!~~!!!!~~~!!7!!~!!!7!!!!!?YPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BGGGGGGP5555PPP555PPPP555PPP55555PP5555PPP555PPPPP555PPP5555GB##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########################################################&&&&\n";

            sleep(m_play_speed);
        }

        void frame34()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGGGPPP5YYYYY5PPGGGGG\n"
                         "GGGGGGGGGGGGGGGGGBBBBBBBBBBBBGGGGPYYJJ?777?JY5PPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP5YJ?777!777?Y5GGBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5?!!!!77!!!!!?JY5PPGGGGPPYJ?JY55YJJJY555YJJY555J??7!!!!777!!7?YPGBB\n"
                         "##########################BBBBBBGPYJ?7!!~~!!!!!!!7?J5P5YJ?7!!!!7?7!!!!7??77!!7?77!!!!77!!!!!7?J5PGBB\n"
                         "###############################BBPY7!!!!!!~~~!77!!!!!??7!!~!77!~~~!777!!!!777!!!!777!!!!777!!7?YPBBB\n"
                         "###############################BBBGP5J7~~~!!!!!!!!77!!!!7?7!~~!!77!!!!777!!!77??7!!!777!!!!7?JY5GBB#\n"
                         "################################BBBBG5J77!!~~!!!!!!!7??7!!!7?77!!!!777!!!!77?7!!7??77!!!77!!!7?5GB##\n"
                         "&&&&&&&&&&#########################BGY7!~~!7!!!!!7??777?JYJ7!!!77!!!!!777!!!7Y5Y?777??7777?J5PGGBB##\n"
                         "&&&&&&&&&&&&&&&&&##################BG5?77!~~~!77?77?JY5PPGG5YJ7!!!!777!!!7?JYPGGGP5J77!77?JYPGGBB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&#&&&##########BG57!~~!!!!~~!7?JY5PGGGP55Y?777!!~!!77??JJ5GGGGPYJ?77!!!7?JYPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BB5?7!!~~~!!!7777??JY55YJ?7!!!!!!7!!!!!7?J5P55YJ?77!!777777J5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BB5?!~~~!!!!!!!7777777??77!!!!!!!!!!777777?????777?777!!7?JYPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BP5J?!!!~~~~!!!~~~!!7!!77777!~~~!!7!~~!!7777!!!77!!!!!777!!7J5G###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#B5?!!!!!~~~~~~~~~~!!!!~~!!!!!~~!!!!!~~!!!!~~~!!7!!~!!!7!!!!!?YPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BGGGGGGP5555PPP555PPPP555PPP55555PP5555PPP555PPPPP555PPP5555GB##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########################################################&&&&\n";

            sleep(m_play_speed);
        }

        void frame35()
        {
            m_frame++;
            clearConsole();

            std::cout << "55555555555PPPPPPPPPPPPPPPPPPPP5555PPP55555555555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555PPPPPPPPP\n"
                         "GGPPPPPPPGGGGGGGGGPGGGGGGGGGGGGGGGGPPP5YYJJYY5PPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP5YJ????JY5PGGGB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ77!!!!!!!7JY5PGGGGGGGPPP5PPPPPPP5PPPPPPPPPPP55Y?7!!777!!!?YPGBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPYJ77!!!!!!!!!7?J55PPP55Y?7!7?YJ?777JYJ?777JYJ7!!!77!!!!77?J5PGBB\n"
                         "################################BBBPY?7777!~~~!!7!!!!7JY?7!!!!!!~!!!77!!!!777!!!!777!!!!777!!7?YPGBB\n"
                         "##################################BGP5J7!~~!!!!~!!!!!!!!!777!!!!!7!!!!!77!!!!!7?7!!!777!!!!7??Y5PGBB\n"
                         "##################################BBBBGPJ77!~~!!!!!!!77??J55Y?7!!!!!77!!!!!77?Y555Y?7!!!77!!!7?YGBB#\n"
                         "#####################################BG57!~!!!!!~!!77?Y5PGGPJ7!!77!!!!!777!!!?YPGGGPYJ77!!7?JY5PGB##\n"
                         "&&&&&&&&&&&###########################BPJ77!~~!!77!!!7J5GGGG5J?7!!!!777!!!77?J5PGGGY?7777?JYPGGBBB##\n"
                         "&&&&&&&&&&&&&&&&&&&##################BB57~~~!!!~~!!!7?YPGGBGY??7777!!!!!77!!77YPGGGPYJ?7!!7?JYPGBB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BGPJ7!!~~~!!!!~!7J5PGGP5J?7!!!!!!!!!!!7?JYPPGG5?777777!!7?YGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BG57~~~!!!!~~!!7?Y5PGGPJ7!!!7!!!!!!7!!!!7?Y5PP5YJ?7!!!7?JYPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BBG5J7!!~~~~!!!~~!7?JY5PY?77!~~!77!~~!!777777?J?7!!!777!!7J5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GJ7!!~~~~~~~~~~~~!!~~~!!!!~~~~!!!~~~~!!~~~!!!!!!~!!!!!!!!?YPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GP55555JJJJYYYJJJYY5YYJYY55YJJJY5YJJJJYYYYJYY55YJJY555YYJY5GB##&\n"
                         "@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########################################################&&&\n";

            sleep(m_play_speed);
        }

        void frame36()
        {
            m_frame++;
            clearConsole();

            std::cout << "55555555555PPPPPPPPPPPPPPPPPPPP5555PPP55555555555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555PPPPPPPPP\n"
                         "GGPPPPPPPGGGGGGGGGPGGGGGGGGGGGGGGGGPPP5YYJJYY5PPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP5YJ????JY5PGGGB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ77!!!!!!!7JY5PGGGGGGGPPP5PPPPPPP5PPPPPPPPPPP55Y?7!!777!!!?YPGBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPYJ77!!!!!!!!!7?J55PPP55Y?7!7?YJ?777JYJ?777JYJ7!!!77!!!!77?J5PGBB\n"
                         "################################BBBPY?7777!~~~!!7!!!!7JY?7!!!!!!~!!!77!!!!777!!!!777!!!!777!!7?YPGBB\n"
                         "##################################BGP5J7!~~!!!!~!!!!!!!!!777!!!!!7!!!!!77!!!!!7?7!!!777!!!!7??Y5PGBB\n"
                         "##################################BBBBGPJ77!~~!!!!!!!77??J55Y?7!!!!!77!!!!!77?Y555Y?7!!!77!!!7?YGBB#\n"
                         "#####################################BG57!~!!!!!~!!77?Y5PGGPJ7!!77!!!!!777!!!?YPGGGPYJ77!!7?JY5PGB##\n"
                         "&&&&&&&&&&&###########################BPJ77!~~!!77!!!7J5GGGG5J?7!!!!777!!!77?J5PGGGY?7777?JYPGGBBB##\n"
                         "&&&&&&&&&&&&&&&&&&&##################BB57~~~!!!~~!!!7?YPGGBGY??7777!!!!!77!!77YPGGGPYJ?7!!7?JYPGBB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BGPJ7!!~~~!!!!~!7J5PGGP5J?7!!!!!!!!!!!7?JYPPGG5?777777!!7?YGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BG57~~~!!!!~~!!7?Y5PGGPJ7!!!7!!!!!!7!!!!7?Y5PP5YJ?7!!!7?JYPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BBG5J7!!~~~~!!!~~!7?JY5PY?77!~~!77!~~!!777777?J?7!!!777!!7J5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GJ7!!~~~~~~~~~~~~!!~~~!!!!~~~~!!!~~~~!!~~~!!!!!!~!!!!!!!!?YPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GP55555JJJJYYYJJJYY5YYJYY55YJJJY5YJJJJYYYYJYY55YJJY555YYJY5GB##&\n"
                         "@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########################################################&&&\n";

            sleep(m_play_speed);
            // end of blink
        }

        void blink()
        {
            frame31();
            frame32();
            frame33();
            frame34();
            frame35();
            frame36();
        }

        void handleTwoBlinks()
        {
            blink();
            blink();

            frame37();
        }

        void frame37()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555555555555555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555555PPPPPG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP5YJ???JJYYYY55PPPGGGGGGGGGGGPPGGGGGGGGGGGGGGGGGP5YYJ?777?JYPGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP5YJJ?77!!!!!7?JJY5PPGGGGP5555PPP5YYY5PP55Y555555YJ7!!!!77!!!!?5GBB\n"
                         "###########################BBBBBBBGP5J7!~!!!!!!!!7?JYPPP5YJ7!!!?JJ?!!!7?J7!!!7?J7!!!!777!~!!7?JY5GBB\n"
                         "###############################BBBBBG5J77!~~~!!!!!!!?JJ?!!!!77!~~~!77!!!!!777!!!!!7!!!!!777!!!7?5GBB\n"
                         "##################################BBGY7!!!!!!~~!!!!!!!!!77!!~!!!!!!!!!!7!!!!7777!!!77!!!!!!!7??YPGBB\n"
                         "##################################BBG5?7!~~~~!!!!!!!!77?Y55J?!!!!!!!!!!!!!77?JY5Y??7!!!!7777JJY5GBB#\n"
                         "####################################GY7!!!!!!~~!!!77?Y5PPP5J7!!!!!!!!!!7777??YPP5JJ??77!!!7?YY5GBB##\n"
                         "#########&&&&&&&&&&&&##############BB5?7!~~~!!!!!!!7?5PGGGPY?7!!!!!!!!!!!7JJY5PGPJ?7!!777??J5PGBB###\n"
                         "&&&&&&&&&&&&&&&&&&&&###############BG5?!!!!!!!!!!!!7?YPGGGPJ7777!!!!!!77777?J5PGGPP5J77!!77JY5PGBB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&##############G5?!!~~!!!!!!!!!?YPGGGPJ77!!!!!!!!!!!7?JY5PGGPPY?77777!!!7?5GBB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&##########BBG5?!!!!~~~!!!!!!?Y5PGG5J?7!!!!!!!!!!!!!7JY555YYJ?77!77777?JYPB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&######BP5YJ7!~~~~!!!!~!!!?JYYJJJ?7!!!!!!!!!!!!7?????JJ???7777777!77?5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####B5?7!!!!~~^~~~!!~~~~!!!!~!7!!!!~~!!!!!~~~!!!7777777!!!!7777!!?YGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BY?!!!!~~~~~!!~~~~~!!!~~~!!!!~~!!!!!~~~!!!~~~!!7!!~~!!!!!!~!7J5B###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BGP55PPP5YYY5555YYY555YYYY5555YYY55P5YYY55P55YY5555YYY5PP5YYY5GB##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#############################################################&&&";

            sleep(m_play_speed);
            frame38();
        }

        void frame38()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGPPPPPPPPPPPPPPP55YYY55555555555555PPPGGGGGGGGGGPPP5YYJJYYYJJJJY5GGG\n"
                         "GGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGPYJJ?77777?JJYYYYYYYY5PPGGPPPGGPPP5Y??7777!!!!7777J5GBB\n"
                         "BBBBBBBBBBBBBBBBBBBBB#####BBBBBBBBBBBBBBBBBGG5J7!!!77!!!!!7?JJJ?77?Y5YJ??JY5YJ?77!!!!!77!!!!77?Y5GBB\n"
                         "#######################################BBBBGPY?77!!!!!!7!!!~!!77!!!!777!!!7?77!!!!!!!!!!!777777?5GBB\n"
                         "#######################################BBGY???!!!!!!7!!!!!7!!!~!!77!!!!777!!!!!77!!!!!77!!!!7?JYPGBB\n"
                         "#######################################BBGJ7!~~!!77!!7?J?7!!!77!!!!!7!!!!7?JJ?7!!!77!7!!!77777?J5GBB\n"
                         "#######################################BBPJ77!!~~!7??JYYJ??7!!!!!7!!!!7?JJJYYJ???7!!!77777!7?JY5GGBB\n"
                         "##################################BBBBBBGPJ!~~~!77?JYYYYJ7!!!77!!~~!77?JYYYYY??77!7!77!!7?7777?JPGBB\n"
                         "#####&&&&&&&&&###################BG5555PP5J77!!!!!7?JJJJJ??7!!!!!77!!!7?JYYYYJ?777!!!?77!!!77?J5PGB#\n"
                         "####&&&&&&&&&&&&&&&&&&&&&&########B5YYJ?777!~~~!!7JJJJJJ?7!!!!!!!!!!77?JYYYYY?7!!!77!7!!!777!77J5G##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###B5YYJ?!~~~!!!!!!!77?J??77!!~~~!!!!!!!!7?JJJJ?77!!!!777!!!77?J5PG##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###B5YJJ7!!!~~~~~!!!!!!777!!!!!!!!~!!!7!!!~!777!!!!7777!!7777!77JPB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##B5JJJ7~~~~~~~~~~~!!~~~~!!!~~~~!!!~~~!!!!!~~!!!!!!!!!7!!!!77?Y5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GP5J7~~~~~~~~~~~!~~~~!!!~~~!!!!~~~!!!!!!!!!!!~!!!!!!!!!!7!!7YGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GP555555YYYY555YYY5555YYYY555YYYYYYYYYY55YYYYY5555YYY5PPGBB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########################################################&&&\n";

            sleep(m_play_speed);
            frame39();
        }

        void frame39()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPGGGGGGPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGGGGGGGGGPPPPPPP5YYY5555YYYY5PPPPPPGGPPPPPPPP5YYJJY5PGGGG\n"
                         "GBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGGGGP5YYJ??77!77??77??Y5PPP55YYY555YJ??77777J5GGBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGP5YJ?7!!!!!7!!!~!!77J55YJJ??7!!77777!!!!7?J5PGBBBB\n"
                         "###################################BBBBBBBBBBBGPYJJ?!!!!777!~~~!!7!!~~!7??!!!!7?77!~!!777!!!7?5GBBBB\n"
                         "####################################BBBBBBBG5YYJ7~~!!!7!!!!7???!~~!!7!!~~!777!!~!!777!~~!77?J5PGBBBB\n"
                         "###################################BBBBBBBGPJ!!!!77!!!!7??JY555J?7!!~!!!7!!!!!777!!!!7777!!!7J5GBBBB\n"
                         "####################################BBBBBGGP5J7!~~~!!7?JYPGGGPJ7!!!77!!!!!!77!!!!!777!!!!7??J5PGBBB#\n"
                         "###################################BBBBGP5YJ7!~~!!!!!!7?Y5GPGP5J?7!!!!!77!!!!!777!!!!7777!!7?JPGBBB#\n"
                         "##################################BBGP5Y?!~~!!!!~~~!!7?JY5P55Y?7!!!!!!!!!!777!!!!777!!!!!7??JYPGBBB#\n"
                         "##&&&&&&&&&&&&&&&&################BBY!~~!!!!~~~~!!!!~!7?YYJ7!!!!!!!!!!!77!!!!77!!!!!!777!!!7?Y5PGBB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&#############BB5?7!~~~~~!!!~~~!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7!!!!!7777777?YPGB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&#########BB57~~~~!~~~~~~~~~!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!77!!!!777??Y5GB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BB5?!!~~~~~!~~~~~!!!!!!!!!!!~~~!!!!!!!!!!!!!!!!7!!!!!77777!!7?YPGB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####B5!~~~~^^~~~~~~~~!!!~~~~~~!~~~~~!!!~~~~!!!!!~~!!!!!!!!!!!!!!?JPBB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BP?!!!~~!!!!~~~~!!!~~~~!!7!!~~!!!!~~~!!!!!~~!!!!!~~!!77!!~!!?YPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###GGP555PPP5YYY5PP555555P55YYY55P55YY55P55YY55PP5YYY5PP55Y55PB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#########################################################&&";

            sleep(m_play_speed);
            frame40();
        }

        void frame40()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555555555555P555555555P5555555PPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP55YYJ????JJJ?7?JJY5P55YYYYYYJJJJ??7?5PGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGP5YJ?7!!!!7!!~!!!7!!!!7?J?!!!7777!!!!7?Y5GBBBBB\n"
                         "######################################BBBBBBBBBBBGG5YJ?!!!!77!~~!!!!!~!!!!!!~~!77!!~~!77!!!!?YGBBBBB\n"
                         "#########################################BBBBBBP5YY7~~!!!!!!!77?7!~~!!7!!!!!!!!!~!!77!!!!!7?Y5GBBBBB\n"
                         "#########################################BBBBBG57~~~!!!!!!77?JY55J77!!!!!!!!~!!!7!!!!!77!!!7?YGBBBB#\n"
                         "########################################BBBBBGG5J7!!~~!7?JJ5555YJ7!!!!7!!!!!!!!!!!!77!!!!7?JYPGBBB##\n"
                         "#######################################BBBBG5YJ?!~~~!!7JY55PPY777777!~!!!7!!!!!777!!!7777!!7?5GBBB##\n"
                         "#######################################BGYJ?7~~~~!!!~~!!?JY55Y?7!!~~!!7!!!!777!!~!777!!!!7??J5PGBB##\n"
                         "&&&&#######&&&&&&&&&&&&&&&#############B5?~~~~!!~~~~!!!~~!!?J?!!!!!!!~~!!77!!!!!77!!!!!77!!77JY5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########BP?!!~~~~~~!!~~~~!!!~~!!!!!~~!!!!!~!!77!~~!!7!!!!!77777?J5GB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BP?!~~~!!~~~~~~!!!~!!!!!~~!!!!~~~!!!!!!!!7!!!!!777!!!7?JYPGB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BP?!~~~^~~~~~~~~!!!!~~~!!!~~~~!!!~~~!!!!~~!!77!!!!777!!7?5BB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###P?~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!~~~!!!~~~~!!!!!!!7JPB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GP55YJYY5YJJJJYYYJJJYYYJJJJYYYJJJJYYYJJJYYYJJJJYYYJJJJ5G##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BBBBB#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB###&&\n";

            sleep(m_play_speed);
            frame41();
        }

        void frame41()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555555555555P555555555P5555555PPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP55YYJ????JJJ?7?JJY5P55YYYYYYJJJJ??7?5PGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGP5YJ?7!!!!7!!~!!!7!!!!7?J?!!!7777!!!!7?Y5GBBBBB\n"
                         "######################################BBBBBBBBBBBGG5YJ?!!!!77!~~!!!!!~!!!!!!~~!77!!~~!77!!!!?YGBBBBB\n"
                         "#########################################BBBBBBP5YY7~~!!!!!!!77?7!~~!!7!!!!!!!!!~!!77!!!!!7?Y5GBBBBB\n"
                         "#########################################BBBBBG57~~~!!!!!!77?JY55J77!!!!!!!!~!!!7!!!!!77!!!7?YGBBBB#\n"
                         "########################################BBBBBGG5J7!!~~!7?JJ5555YJ7!!!!7!!!!!!!!!!!!77!!!!7?JYPGBBB##\n"
                         "#######################################BBBBG5YJ?!~~~!!7JY55PPY777777!~!!!7!!!!!777!!!7777!!7?5GBBB##\n"
                         "#######################################BGYJ?7~~~~!!!~~!!?JY55Y?7!!~~!!7!!!!777!!~!777!!!!7??J5PGBB##\n"
                         "&&&&#######&&&&&&&&&&&&&&&#############B5?~~~~!!~~~~!!!~~!!?J?!!!!!!!~~!!77!!!!!77!!!!!77!!77JY5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########BP?!!~~~~~~!!~~~~!!!~~!!!!!~~!!!!!~!!77!~~!!7!!!!!77777?J5GB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BP?!~~~!!~~~~~~!!!~!!!!!~~!!!!~~~!!!!!!!!7!!!!!777!!!7?JYPGB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BP?!~~~^~~~~~~~~!!!!~~~!!!~~~~!!!~~~!!!!~~!!77!!!!777!!7?5BB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###P?~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!~~~!!!~~~~!!!!!!!7JPB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GP55YJYY5YJJJJYYYJJJYYYJJJJYYYJJJJYYYJJJYYYJJJJYYYJJJJ5G##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BBBBB#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB###&&\n";

            sleep(m_play_speed);
            frame42();
        }

        void frame42()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555555555555P555555555P5555555PPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP55YYJ????JJJ?7?JJY5P55YYYYYYJJJJ??7?5PGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGP5YJ?7!!!!7!!~!!!7!!!!7?J?!!!7777!!!!7?Y5GBBBBB\n"
                         "######################################BBBBBBBBBBBGG5YJ?!!!!77!~~!!!!!~!!!!!!~~!77!!~~!77!!!!?YGBBBBB\n"
                         "#########################################BBBBBBP5YY7~~!!!!!!!77?7!~~!!7!!!!!!!!!~!!77!!!!!7?Y5GBBBBB\n"
                         "#########################################BBBBBG57~~~!!!!!!77?JY55J77!!!!!!!!~!!!7!!!!!77!!!7?YGBBBB#\n"
                         "########################################BBBBBGG5J7!!~~!7?JJ5555YJ7!!!!7!!!!!!!!!!!!77!!!!7?JYPGBBB##\n"
                         "#######################################BBBBG5YJ?!~~~!!7JY55PPY777777!~!!!7!!!!!777!!!7777!!7?5GBBB##\n"
                         "#######################################BGYJ?7~~~~!!!~~!!?JY55Y?7!!~~!!7!!!!777!!~!777!!!!7??J5PGBB##\n"
                         "&&&&#######&&&&&&&&&&&&&&&#############B5?~~~~!!~~~~!!!~~!!?J?!!!!!!!~~!!77!!!!!77!!!!!77!!77JY5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########BP?!!~~~~~~!!~~~~!!!~~!!!!!~~!!!!!~!!77!~~!!7!!!!!77777?J5GB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BP?!~~~!!~~~~~~!!!~!!!!!~~!!!!~~~!!!!!!!!7!!!!!777!!!7?JYPGB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BP?!~~~^~~~~~~~~!!!!~~~!!!~~~~!!!~~~!!!!~~!!77!!!!777!!7?5BB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###P?~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!~~~!!!~~~~!!!!!!!7JPB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GP55YJYY5YJJJJYYYJJJYYYJJJJYYYJJJJYYYJJJYYYJJJJYYYJJJJ5G##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BBBBB#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB###&&\n";

            sleep(m_play_speed);
            frame43();
        }

        void frame43()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555555555555P555555555P5555555PPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP55YYJ????JJJ?7?JJY5P55YYYYYYJJJJ??7?5PGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGP5YJ?7!!!!7!!~!!!7!!!!7?J?!!!7777!!!!7?Y5GBBBBB\n"
                         "######################################BBBBBBBBBBBGG5YJ?!!!!77!~~!!!!!~!!!!!!~~!77!!~~!77!!!!?YGBBBBB\n"
                         "#########################################BBBBBBP5YY7~~!!!!!!!77?7!~~!!7!!!!!!!!!~!!77!!!!!7?Y5GBBBBB\n"
                         "#########################################BBBBBG57~~~!!!!!!77?JY55J77!!!!!!!!~!!!7!!!!!77!!!7?YGBBBB#\n"
                         "########################################BBBBBGG5J7!!~~!7?JJ5555YJ7!!!!7!!!!!!!!!!!!77!!!!7?JYPGBBB##\n"
                         "#######################################BBBBG5YJ?!~~~!!7JY55PPY777777!~!!!7!!!!!777!!!7777!!7?5GBBB##\n"
                         "#######################################BGYJ?7~~~~!!!~~!!?JY55Y?7!!~~!!7!!!!777!!~!777!!!!7??J5PGBB##\n"
                         "&&&&#######&&&&&&&&&&&&&&&#############B5?~~~~!!~~~~!!!~~!!?J?!!!!!!!~~!!77!!!!!77!!!!!77!!77JY5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########BP?!!~~~~~~!!~~~~!!!~~!!!!!~~!!!!!~!!77!~~!!7!!!!!77777?J5GB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BP?!~~~!!~~~~~~!!!~!!!!!~~!!!!~~~!!!!!!!!7!!!!!777!!!7?JYPGB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BP?!~~~^~~~~~~~~!!!!~~~!!!~~~~!!!~~~!!!!~~!!77!!!!777!!7?5BB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###P?~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!!~~~!!!~~~~!!!!!!!7JPB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GP55YJYY5YJJJJYYYJJJYYYJJJJYYYJJJJYYYJJJYYYJJJJYYYJJJJ5G##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BBBBB#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB###&&\n";

            sleep(m_play_speed);
            frame44();
        }

        void frame44()
        {
            m_frame++;
            clearConsole();

            std::cout << "5555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555PPP55PP5555PPPPPP5555P555555PPPPPPPPPPPPPPP\n"
                         "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555PPPPPGPGGGGGGGGGGGGGPPPP555YY55PPGGGGGG\n"
                         "GGBBBBBBBBBBBBBBBBBBBBBBBBBGGGGGGGGGGGBBGGGGGGGGPGP5YJJJ?7777??J5PPPGGGGGGGGGGGP5YJJ??77777?JYPGBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPYJ?7!!!!!!7!!!!!7?JYPPYJJJY555Y??7!~!!777!!!!?5GBBBB\n"
                         "###################################BBBBBBBBBBBGPJ!!!!777!~~!!777!~~!??7!~~!7??7!~!!77!!!!!7?JYPGBBBB\n"
                         "###################################BBBBBBBBBBBGP5?77!!!777?7!~!!7??7!!!!77!!~!7?77!~!!777!!!7?5GBBBB\n"
                         "#####################################BBBBBBGP5YY?!!!!777!!!77?JY555Y??7!~~!777!!!!77!!!!!77?Y5PGBBB#\n"
                         "#####################################BBBBBBG5J777777!~~!!7??J5PPP5Y?!!!777!!!!777!~~!77777!77JPBBBB#\n"
                         "####################################BBBBBBBGPYJJ7~~~!77!!!!7JY5PP5YJ?7!!~!!77!!!!7777!!!!7??JYPBBBB#\n"
                         "#&&##############################BBBBBBGP5YJ?!!!!!!!!~~!!7??JY55YJ?!!!!777!!!!7?7!!!!77?7777?JPBBBB#\n"
                         "&&&&&&&&&&&&&&&&################BBBBGPYJ?!~~~!!!!~~~!!77!!!!?J?7!~!777!!!!!777!!!77777!!!7??J5GBBB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&#&#########BG5YY7~~~~!!!~~~!!77!~~~!77!~~~!!!!~~~!777!!!!7777!!!77777!7?YPBB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&#######BGY7~~~~!!~~~~~!!!!~!!!7!!!~!!77!!~!!!!!!!!!777!!!!!77!!!!77?JYPBB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&####G5J7!~~^~~!!~~^^~!77!~~!!77!~~~!77!~~~!777!!!!777!!!!7777!!7?Y5PGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###GJ!^~~^^^^~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~!!!!!!~~!!!!!!!!!!!!!!7?J5B#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BG5JJ?777?J?77777??77!77???7!!7???7!!7???7777???7!!77??77!77??JYYPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BBGGGBBBBGGGGGBBGGGGGBBGGGGGBBGGGGGBBGGGGGGGGGGGGGGGGGGGGBBB###&\n";

            sleep(m_play_speed);
            frame45();
        }

        void frame45()
        {
            m_frame++;
            clearConsole();

            std::cout << "55P555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5P5PP555PPPPPPPP555PPPPP555PPPPPPPPPPPPPPPPPPPPPPPPPPPP\n"
                         "PPPPPPPPPPPGPPPPPGGGPPPPPPPPPPPPPPPPPPPPPPP555PPPPPGGGGGGGGGGGGGGGGGPPP555555P5555555PPPPPGGGGGGGGGG\n"
                         "GBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGP5YYJ????7777?JJ5PPPGGGGGPGGGGGP5YJJ???7777?J???JYYYYYYY5PGBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP5YJ!!~~!77!!!!7?JYP5YJJJY55YJJ?7!!!7777!!!!7???J5YYYYYY5GBBBBBBB\n"
                         "#################################BG5YYJ??7!!~!!777!~~!7?7!~~!??7!!!!777!!!!777!!!!7?JYYYYY5PBBBBBBBB\n"
                         "################################BBGP5YJ!!~~!77!!!!777!~~!777!!!7???7!!!!77!!~!777!!!7?JYYJY5GBBB####\n"
                         "#################################BG5YJ??77!!~~!77!!~!!77!!~~!7???JJYJJ7!!!!777!!!!7??JJY5PGBBB######\n"
                         "#################################BGP5YJ7!~~!7!!~~!777!~~!777!~!7?YYJJ??J?7!!!!7?77!7?JY5PGBB########\n"
                         "#################################BP5JJJ??7!~~~!77!!!!777!!~~!7????JYYJ?7!!7??7!!!7???JJYPGBB########\n"
                         "################################BBG5YYJ!!~!!7!~~~!777!~!!77!!!!!?JYYYYYYJ?7!!7??7!!!!?JY5PGGBBB#####\n"
                         "&&&&&&&&&&&&&&&&&&&##############BPYJJ?777!~~~!!7!!~!!77!~~~!777??JYYYYJJJJ??7!!!7777!!7?JY5GBBB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&###########BG5JJ?!~~~!77~~~!777!!!!77!!!!!7?JJJJJJJ?7777?77!!!!777!!!7JYPGB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#####BGP57!~~!!7!~~~!77!!~~!77!!~~!77!!!!7J?7!!!7??7!!!777!!!!7??777?J5B##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&###G5YYJ7!!~~~~!77!~~!777!~~!777!~!!77!!~!7??7!!!77?7!!!77?7!!!7?Y5PG###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##G5J?7~~~~~~~~~~~~~~~~~~~~!~~~~~!!~~!!~!!~~!!!!!!!!!!!!!!!!!7JYPB###&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BPPPPYJ?7!7????777?J??777???7777???7777???777????777??J?777?J5G##&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BGGGGBBBGGGGBBBGGGBBBBGGGBBBBGGGGBBGGGGGBGGGGGBBBBGGGGB###&&&&\n";

            sleep(m_play_speed);
            frame46();
        }

        void frame46()
        {
            m_frame++;
            clearConsole();

            std::cout << "BBBBBBBBBBBBGGGGGGGGGGGGGGGGGGGGGGGGGPJ???77!!7??Y5PPPGGGGGPPPP5JJ?7777777!77?JYY5PGGGBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ!!~~!77!!!!7?JYP5J??JY55YJJ?7!!!!777!!!!7?JYPGGGBBBBBBBBBBBBB\n"
                         "##########################BBBBBBBBBBBGJ?77!~~~!777!~~!7?!!~~!7?7!!!!777!!~!777!!!!!?J5PGBBBBBBB###BB\n"
                         "##################################BBBP?!~~!777!!!!777!~~!777!~~!7??7!!!7??7!!!!777!!7?YPGBBBBBB#####\n"
                         "##################################BBBPJ?77!~~!!77!!~!!77!!~~!777777???????JJJ?7!!!7?JY5PGBBBBB######\n"
                         "####################################BG?!!~!!7!!~~!777!!!!777!!~!7???777?JJJ?77???77!!7?Y55PGBB######\n"
                         "####################################BGYJJ?!~~~!77!!~!!77!!~~!777777???????JYJ?7!!!???777??JYPGGBB###\n"
                         "####################################BGY????77!~~~!777!~~!777!!!!7??????JJJJ??JJJ?7!!!7????7?JYY5PB##\n"
                         "&&&&&&&&&&####&#####################BGJ??7!~~~!!7!!~!!77!~~~!777777??J???JJJJJJ?????7!!!777????JYB##\n"
                         "&&&&&&&&&&&&&&&&&&&&#############BGPP5?!~~!!7!~~~!777!!!!77!!!~!77?777???J???????7!!!7777!!!7?JY5B##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&######B5J???77!!~~~!77!!~~!77!!~~!77!!~!!7?7!!!7???7!!7777!!!77?77!!7JPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####B5J?7!~~~~!77~~~!77!~~~!777!~~!777!~~!777!~!!7?7!!!!7?7!!!!7?JY5GB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GY!~~~~~~~~~~~~~~~~~~~~~~~~~~!!~~~~~!!~~~~~!!!~~!!!!!!!!!!77!7?YG##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GP5Y?77??JJ?77??JJ?77?JJJ?77??JJ?77??JJ??7?JJJ?77??JJ?777?JY55PB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB####&&\n";

            sleep(m_play_speed);
            frame47();
        }

        void frame47()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555PPPPPPPPPPPPPPPPPPPPPPPPPP5PPPPPPPGGGGGGGGGGGGGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG55YJJ??JY55PPPP55PGGPP55YJJ?JJJ???7?YY5PPGGBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP?!!!!7!!!!7?JY?7!7JJJ7!!!777!~~!77!!!!7?Y5PBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5J7!~~!!77!!!!!77!~!!777!!!!777!!!!777!!!7?YPPGBBBBBBBB#BBBBB\n"
                         "##############################BBBB#BBBP?!!!!7!!!!!77!~~!!77!!~!!77!!!77?7!!!!!77!!!7J5GBBBBBBB###B##\n"
                         "##################################BBBBGY?7!!!!!!!!!!!!7!!!!!!!!!!!77??J5P5Y?7!!!777?Y5GBBBBBB#######\n"
                         "####################################BBG5YJ?77!!!!!!!!!!!!!!!!!!!!!!!7?JYPGGP5Y?7!!77?Y5PGGBB########\n"
                         "#####################################BGPYJ?!!!!!!!!!!!!!!!!!!!!!!!!77??YPGGGP5YJJ?77!!7?J5PGBBBB####\n"
                         "#####################################BBBGPY?7!!!!!!!!!!!!!7!!!!!7!!!!7?YPPGGG5Y?77777777!7?J5PGB####\n"
                         "#####################################BBGPPY?7!!!!!!!!!!!!!!!!!!!!!!7!!!7?JYPPGP5J?7!!!777!!!7?YG####\n"
                         "&&&&&&&&&&&&&&&&&###################BBGJ!!!!!!~~!!!!!!!77!!!!!!!!!!!!!777777?JYYJ?7777!!77777?JPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&########BBGY7!!~!!!!!!!!!!!!!!!!!!!!!!!!!!!!77777!!77777777777!!7JYPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BGP5?!!!!!!!!!!!!!~!!!!!!!!!!!!!!!!77!!!!777!!!77777!7777??YPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BP7~!!~~~~!!!~~~!!!~~~~!!!!~!!!!!~~!!!!!~~!!!!!!!!!!!!!!!7?J5GB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GY?7!~~!!!!~~!!!!~~~!!!!~~~!7!!!~!!!!!!!!77!!!!777!!~!7777?YG##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BBPYY55PP5555PPP5555PPP5555PP5555PPP5555PPP555PPPP555PPGBB##&&&\n";

            sleep(m_play_speed);
            frame48();
        }

        void frame48()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555PPPPPPPPPPPPPPPPPPPPPPPPPP5PPPPPPPGGGGGGGGGGGGGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG55YJJ??JY55PPPP55PGGPP55YJJ?JJJ???7?YY5PPGGBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP?!!!!7!!!!7?JY?7!7JJJ7!!!777!~~!77!!!!7?Y5PBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5J7!~~!!77!!!!!77!~!!777!!!!777!!!!777!!!7?YPPGBBBBBBBB#BBBBB\n"
                         "##############################BBBB#BBBP?!!!!7!!!!!77!~~!!77!!~!!77!!!77?7!!!!!77!!!7J5GBBBBBBB###B##\n"
                         "##################################BBBBGY?7!!!!!!!!!!!!7!!!!!!!!!!!77??J5P5Y?7!!!777?Y5GBBBBBB#######\n"
                         "####################################BBG5YJ?77!!!!!!!!!!!!!!!!!!!!!!!7?JYPGGP5Y?7!!77?Y5PGGBB########\n"
                         "#####################################BGPYJ?!!!!!!!!!!!!!!!!!!!!!!!!77??YPGGGP5YJJ?77!!7?J5PGBBBB####\n"
                         "#####################################BBBGPY?7!!!!!!!!!!!!!7!!!!!7!!!!7?YPPGGG5Y?77777777!7?J5PGB####\n"
                         "#####################################BBGPPY?7!!!!!!!!!!!!!!!!!!!!!!7!!!7?JYPPGP5J?7!!!777!!!7?YG####\n"
                         "&&&&&&&&&&&&&&&&&###################BBGJ!!!!!!~~!!!!!!!77!!!!!!!!!!!!!777777?JYYJ?7777!!77777?JPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&########BBGY7!!~!!!!!!!!!!!!!!!!!!!!!!!!!!!!77777!!77777777777!!7JYPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BGP5?!!!!!!!!!!!!!~!!!!!!!!!!!!!!!!77!!!!777!!!77777!7777??YPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BP7~!!~~~~!!!~~~!!!~~~~!!!!~!!!!!~~!!!!!~~!!!!!!!!!!!!!!!7?J5GB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GY?7!~~!!!!~~!!!!~~~!!!!~~~!7!!!~!!!!!!!!77!!!!777!!~!7777?YG##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BBPYY55PP5555PPP5555PPP5555PP5555PPP5555PPP555PPPP555PPGBB##&&&\n";

            sleep(m_play_speed);
            frame49();
        }

        void frame49()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP555PPPPPPPPPPPPPPPPPPPPPPPPPP5PPPPPPPGGGGGGGGGGGGGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG55YJJ??JY55PPPP55PGGPP55YJJ?JJJ???7?YY5PPGGBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP?!!!!7!!!!7?JY?7!7JJJ7!!!777!~~!77!!!!7?Y5PBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5J7!~~!!77!!!!!77!~!!777!!!!777!!!!777!!!7?YPPGBBBBBBBB#BBBBB\n"
                         "##############################BBBB#BBBP?!!!!7!!!!!77!~~!!77!!~!!77!!!77?7!!!!!77!!!7J5GBBBBBBB###B##\n"
                         "##################################BBBBGY?7!!!!!!!!!!!!7!!!!!!!!!!!77??J5P5Y?7!!!777?Y5GBBBBBB#######\n"
                         "####################################BBG5YJ?77!!!!!!!!!!!!!!!!!!!!!!!7?JYPGGP5Y?7!!77?Y5PGGBB########\n"
                         "#####################################BGPYJ?!!!!!!!!!!!!!!!!!!!!!!!!77??YPGGGP5YJJ?77!!7?J5PGBBBB####\n"
                         "#####################################BBBGPY?7!!!!!!!!!!!!!7!!!!!7!!!!7?YPPGGG5Y?77777777!7?J5PGB####\n"
                         "#####################################BBGPPY?7!!!!!!!!!!!!!!!!!!!!!!7!!!7?JYPPGP5J?7!!!777!!!7?YG####\n"
                         "&&&&&&&&&&&&&&&&&###################BBGJ!!!!!!~~!!!!!!!77!!!!!!!!!!!!!777777?JYYJ?7777!!77777?JPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&########BBGY7!!~!!!!!!!!!!!!!!!!!!!!!!!!!!!!77777!!77777777777!!7JYPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BGP5?!!!!!!!!!!!!!~!!!!!!!!!!!!!!!!77!!!!777!!!77777!7777??YPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BP7~!!~~~~!!!~~~!!!~~~~!!!!~!!!!!~~!!!!!~~!!!!!!!!!!!!!!!7?J5GB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GY?7!~~!!!!~~!!!!~~~!!!!~~~!7!!!~!!!!!!!!77!!!!777!!~!7777?YG##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BBPYY55PP5555PPP5555PPP5555PP5555PPP5555PPP555PPPP555PPGBB##&&&\n";

            sleep(m_play_speed);
            handleLick();
        }

        void handleLick()
        {
            // first lick
            frame50();
            frame51();
            frame52();
            frame53();
            frame54();
            frame55();
            frame56();
            frame57();
            frame58();
            frame59();
            frame60();
            frame61();

            // second lick
            frame54();
            frame55();
            frame56();
            frame57();
            frame58();

            // continue
            frame62();
        }

        void frame50()
        {
            // start of lick
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGGGGGGGGGGGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP5YYJYYYJ?JY5PGGGGGGGGPP5YYYYY5PPGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ?7!!!777!!7?JY5PGP5Y?7!!777!!!?J5PGBBBBBBBBBBBBBBBBBBBBBBB#BBBB\n"
                         "###############################BBBGY7!!77!!!!!7!!~!7?J7!!!77!!!!777!!7?5GBBBBBBBBBBBB###############\n"
                         "#################################BG5?7!!!!77!!!!!!!!!!!77!!!!7?7!!!!7YY5GGBB#BB##BBB################\n"
                         "################################BBPY?7!!!7!!!!!7!!!!77!!!!77!!!!777!!!7?Y5GGBB######################\n"
                         "###############################BBBG5?7!!!!!!!!!!!!!!!!!!7!!!!777!!!!777777?JYPBB####################\n"
                         "################################BBGY?7!!!!!!!!!!!!!!!!!!!!777777?J??77777777J5GBB#########&####&&&&&\n"
                         "###########&&&&&&&&#############BP5J7!!!!!!!!!!!!!!!!!!!!!!77777JYYYYJ?77!7?J5PGBBBB##############&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&########BBY7~!!!!~!!!!!!!!!7!!!!!!!!!!77?JYPPPYJ?7777777?J5PGB############&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&#######BG5?7!~~!!!!!!!!7!!!!!7!!~!!!7!!!7J5PPPYJ?7!!!777777JPB#########&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&###B5YJ7~~~!!!~~~!7!~~~!!!!~~!!!!!!777!!!7?J?7!!777!!!7?JYPBBBBBBBBB####&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&###GJ!~~~~~!!~~~!!~~~~~~~~~~~!~~~~!!!~~!!!!!!!!!!!~~!7!!7YGBG5Y???YY55PG#&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&##BGP5YY55P5YYY555YYY55YYYY555YYY555YYY555YJYY55YYY55PGGB#BG5YY5PPGGGG#&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&################################################&&&&&&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
        }

        void frame51()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPGGGGGGGGPPPGGGGPPPP5555YYYJY5PPGGGGGGBBBGGGGBBGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBB\n"
                         "GGBBBBBGBGGGGGGGGGBBBBBBBBBBBBBBBBBGGGPYJ?7777!!!!7?JYPPGGGGBBGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGG5?!!!!!!!~!!7777?Y5GGGGGP5J??J5GBBBBBBBBBBBBBBB###############\n"
                         "###############################BBBBBBG5J77!!!!!!!!!!!7JY5PP5Y?7!!7?JYPGBBBBBBB######################\n"
                         "################################BBBBP5J7!!!!!!!!!!!7!!!7??7!!!777!77?JYPGBBBB#######################\n"
                         "################################BBGY7!!!!!!!!!!!!!!!!!!!!!!!!!!!777!!!7?JY5PGBB#####################\n"
                         "################################BBPY?7!!~!~!!!!!!!7!!!!!!!!!!!!!!!!!!77!!77?Y5GB####################\n"
                         "###############################BG5J7!!~!!!!~!!!!!!!!!!!!!!!!!!!!!!!!!!!777!7?YPG#############&#&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&###########BPJ!~~!!!!~!!!!!~!!!!!!!!!!!!!!!!!!!!777!!!777?YPBB#################&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&######BG5J77!~~~!!!!~!!!!!!!!!!!!!!!!!!!!!!!!!!!77777?JPBB####BGGPGGBBGGB###&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&###GY7!!!!!!!!~~!!!!!!!!!!!!!!!!!!!77?J?777777777777J5GGBBGP5J?7?JYYJJYPB#&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&##BP?~~~~!!~~~~~~~~~~!!~~~~!!!!!!!!!7?JY5YJ?7777!!!77?J55YJ77!!777!!!7J5B#&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#B57!!77?7!!!77!!!!77!!!!777!!!77?7?JYPGGGGPY?7!77??J5PP5J77777777777JPB&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&#BGGGGBBGGGGGBGGGGGGGGGGGGGGGGGGBBBBBB#####BBGPGGGB#####BGGGGGGGGGGGB##&&\n";

            sleep(m_play_speed);
        }

        void frame52()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPGGGGGGGGPPPGGGGPPPP5555YYYJY5PPGGGGGGBBBGGGGBBGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBB\n"
                         "GGBBBBBGBGGGGGGGGGBBBBBBBBBBBBBBBBBGGGPYJ?7777!!!!7?JYPPGGGGBBGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGG5?!!!!!!!~!!7777?Y5GGGGGP5J??J5GBBBBBBBBBBBBBBB###############\n"
                         "###############################BBBBBBG5J77!!!!!!!!!!!7JY5PP5Y?7!!7?JYPGBBBBBBB######################\n"
                         "################################BBBBP5J7!!!!!!!!!!!7!!!7??7!!!777!77?JYPGBBBB#######################\n"
                         "################################BBGY7!!!!!!!!!!!!!!!!!!!!!!!!!!!777!!!7?JY5PGBB#####################\n"
                         "################################BBPY?7!!~!~!!!!!!!7!!!!!!!!!!!!!!!!!!77!!77?Y5GB####################\n"
                         "###############################BG5J7!!~!!!!~!!!!!!!!!!!!!!!!!!!!!!!!!!!777!7?YPG#############&#&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&###########BPJ!~~!!!!~!!!!!~!!!!!!!!!!!!!!!!!!!!777!!!777?YPBB#################&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&######BG5J77!~~~!!!!~!!!!!!!!!!!!!!!!!!!!!!!!!!!77777?JPBB####BGGPGGBBGGB###&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&###GY7!!!!!!!!~~!!!!!!!!!!!!!!!!!!!77?J?777777777777J5GGBBGP5J?7?JYYJJYPB#&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&##BP?~~~~!!~~~~~~~~~~!!~~~~!!!!!!!!!7?JY5YJ?7777!!!77?J55YJ77!!777!!!7J5B#&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#B57!!77?7!!!77!!!!77!!!!777!!!77?7?JYPGGGGPY?7!77??J5PP5J77777777777JPB&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&#BGGGGBBGGGGGBGGGGGGGGGGGGGGGGGGBBBBBB#####BBGPGGGB#####BGGGGGGGGGGGB##&&\n";

            sleep(m_play_speed);
        }

        void frame53()
        {
            m_frame++;
            clearConsole();

            std::cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGBBG5YJJ?777?J5PPGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGG5YJ7!!~!!!!!!!7?Y5PGGBBGGP5YY5PGBBBBBBB##BBBBBBBBBBBBBBBBBB###\n"
                         "##################################BBGPJ7!!!!7!~~~!7!!!!7JY5PP5Y??77?YGBBBBBBB#######################\n"
                         "##################################BBGP5J77!~~~!!!!!!!7!!!!7?77777??J5PGBBBBBB#######################\n"
                         "################################BBPJ?77!!!!!!!!~~!7!!!!777!~~!77!!!!7?Y5GGBBB#BB####################\n"
                         "###############################BBG5J7!!!!!!!!!!!!!!~!7!!!!!!!!!!!777!777?J5PGBB#####################\n"
                         "###############################BGPYJ77!!~~!!7!!!!77!!!!!!!!!!!777!!!7!!!!77?J5GB#######BBGGBBB######\n"
                         "&&&&&&&&&&&&&&&###############BP?7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!777!!!!77777?YPBB##BBGP5YYYY5PGB####\n"
                         "&&&&&&&&&&&&&&&&&#&&&&#######BGPJ7!!~~!!!!!!!!!!~!!!!!!!!!!!!!!77777!!777777?YPBBBGP5YJ77????77JPB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&####BP5Y7!!!!!!~~!!!!!~!!!!!!!!!!!!!!77!!!7777777777J5PBBPY?777?7!777??YPGB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&###B57~~!!7!~~~!!!~~~!!!!~~!!!!!!!777!!7??7!77777777?Y5PGGPY?7!!7777!77J5G##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&##B57~~~~~~~~~~~~~~~~~~~~~~~~!!!!!!!7?Y5PPYJ?!!!!!!!!7?YPGG5?!!!!!!!!7J5G#&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&##PJ??JYYJ??JJJJ???JJJ???JJJ??JJYY5PGGB###BGPYJJ??JYY5GGBG5???JJJJ??JYGB#&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&########BB##BBBBBBBBBBBBBBBB#######################################&&&&\n";

            sleep(m_play_speed);
        }

        void frame54()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGGGGGP55J????Y5PGGGGBBGGPPPPGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGP5J?7!!!!!!!77?Y5PGGGGYJ??JYPGBBBBBBBBBBBBBBBBB#BBB#BBBBBB#\n"
                         "#################################BBBBBBBGY?!!!7!!~~!77!~!!7J5PP5J7!!!7?YPGBBBBBB####################\n"
                         "####################################BBBBP5J77!!~!!!!!!!77!!!!7?7!!!77777JPGBBBBBB###################\n"
                         "####################################BB5?7!!!!!!!!!!!!7!!!!777!~~!77!!!7?J5PGBBBB######B#############\n"
                         "###################################BBG5?7!!!!!!!!!!!!!!!!!!!!!!!!!!!!777!7?JYPGBB###BBGPPPGBB#######\n"
                         "&&&&&&&&&&########################BGPY?!!!!!!!!!!7!!!!!!!!!!!77!!!777!!777777?JPB#BBGPY?77J5PGB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&#&###########BGY7!~!!!!~!!!!!!!!!!!!!!!!!!!!77!!!777!!777?YPB#BPY???77777?YPGB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BBG5?7!!~~!!!!~!!!!!~!!77!!!777!!!!777!!777777JPBBBBG5J?!!7?77!7JPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&###B5?7!!!!!!!!~~!!!!!!!!!!!!!!!!!7?JJ777JYJ?7!77?YPBBBBBG5Y77!!!77JYPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##B57~~!!!~~~~!~~~~!!!!~~!!!!!!!77JY5PP55PPP5J7!!7?J5GBBPY7!!77!!!7JPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BY777??77!7?77!!777!!!7777!!777!!7?Y5J77?Y5?77777?YGBG5?!!777!!7?YG##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BBBBBBBBGBBBGGGGGGGGGGGGGGGGGGGGGBBGGGGGBGGGGGBB####BGPPPGGGPPPG##&\n";

            sleep(m_play_speed);
        }

        void frame55()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP5YYY5PPGGGGGGGGGPPP5YYYPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ?7777!77JYPPGGGPP5J???7!!7?Y5PGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ?7!!!!!!!~!?Y55?7777!!!!!7!!!7J5PGGGBBBBBB##BB#BBBBB#########\n"
                         "############################BB#BBBBGP5?7!!!!!~!!!!!!!77!!!!!77!!!!77!!!7J5PGBBBBB###################\n"
                         "################################BBGJ7!!!!!~!!!!!!!!!7!!!!!!!!!!7!!!!!777!!7?YPGBBB##################\n"
                         "#################################BGYJ7!!!!!7!!!!7!!!!!!!!!!!77!~!!77!!!77777!?YPBBB#################\n"
                         "#################################BGJ7!!!7!~~!!!!!!!77!!!!!7!!!!7?7!!!7?7!!!77JYPGBBBBBBGGGGBB#######\n"
                         "#################################BPJ?7!!!!!!!~~~!7!!!!77!!!!7?????J?J????77!!7?Y5PGGGGPYJJJY5PGB####\n"
                         "&&&&&&&&&&&&&&&&#################BP?!!!!!!!~~!!!!~!!!!!~!!7!!!?Y5YJJJJ?77!!7777!7?JY5YJJ?77!77J5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&#########BPJ7!!!!!!!!!!!!!!!!!777!!!7?J555J??7!7777!!!77777?Y5Y7!!7777!7YPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&####BP5J7!!!!!!!!!!!!!!!!!!!!!!!77!!7777!!7777!!777!!!77J555J?7!!!7?J5PB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&###PJ7!!!!~~~~~~~~~~!!!~~!!!!!~~!!!!!!!!!!!!!77!!!!777!?Y5J7!!777!!7YPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##P?!77??7!77?7!!!777!!7777!!!777!!!777!!!777!!777777?J55?7!777!!7?5G##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BBBBBBBGGBBGGGGGGGGPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBGPPPGGGPPGB##&\n";

            sleep(m_play_speed);
        }

        void frame56()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5P555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGPPPPPPGGGGGGGGGGGGGGGG\n"
                         "GGGGGGBBBBBBBBBBBBBBBGGGGGGGGGGGGGYJJJYYJ??JYY5PGP55JJ??JYYJ??JYYJ???Y5PPGGGGBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5?7!!!!!!!~!!?J?7!!77!~~~!77!~!!7!~~!7JY5PGBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "##########BBBBBBB######BBBBBBBBBBPJ!!!77!~~~!7!~~~!77!~!!7!!!!777!~~!77!!!!?YPGBBBBBBBBBB#BBBBB#####\n"
                         "#############################BBBBPY?7!~~!!7!~~~!7!~~~!7!!~~!77!~~!77!~~!77!!!7J5PGGBBBB#############\n"
                         "##############################BBBP?!!!77!~~!!!!~~~!7!!~~!77!!!?JJ7!7JJJ7!!!7?????JY5GBB#############\n"
                         "###############################BBPY?7!!~!77!~~!77!!!!!7!!~!?JY5PPP5555YJ?77!!!7?777?5PBB############\n"
                         "################################BPJ7!!!!!~~~!!!!!!!7!!!!!7?YYYYYY55YJ??7!!!77!!!!7?YPGBBBGGGBBB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&##########BBPJ77!!~~!!!~~~!!!!!!!77!!!!77???7777!!!777!!!77777J5PPP5YJJY5GBB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&#########BPJ7!!!!!!!~!!!!!~~!!!!!!!7!7!!777!!!777!!!7777!77?Y5YJ??77777?JPB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&########BPJ7!!!!!!!!!!!!!!!!!!!!!!!!!7!!!!77!!!!7777!!77!!7!77777!!7777J5GB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#####BGPY7!!~!!!!!~~!!!!~!!!!!!!!77!!!777!!!7777!77777!!7??7777777!77J5GB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&###GY?77!~~~~~~~~~~~~~~~~~~~!~~~~~!!!!!!!!!!!!!!!!!!!7?JYPY7!!!!!!!7J5G##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GJ7??JJ?77?JJ?77?J??77?JJ?77?JJ?77?JJ?77?JJ??7?JJJ5GBBGY777JJ?77?YPB#&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######BBBBBBBBBBBB#BBBBBB#BBBBBBBBBBBBBBBBBBBBB########BBBBBBBBBB###&\n";

            sleep(m_play_speed);
        }

        void frame57()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP55PPP5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGPPGGGGGGGGGGGGGGGGGGG\n"
                         "BBBBBBBBBBGBGGGGGGGGBGGGGGGGGGBBGPY???JYJ????JY5GPYYJ?777?J?777?J?7!!7?Y5PGGGGBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGY??7!!!!7!!~!!?7!!!!7!!~~~!77!~~!!!!~!!?J5PGBBBBBBBBBBBBBBBBBBBBBB\n"
                         "#######################BBBBBBBBBBGJ77!!7!!~~!!7!~~!77!~~!77!!!!!77!~~!77!!!!?Y5GGBBBBBBBBBBBBBB#BBBB\n"
                         "#############################BBBBGY?7!!!~!7!!~~!!7!~~!77!!~~777!!!?YJ!!~!77!!!!?Y5PGBBB#############\n"
                         "###############################BBPJ7!~!7!!~~!!!!~~!77!~~!777!!?JY555555Y?!!!7?7777?J5PBB############\n"
                         "###############################BBGY?7!!!!!7!!~~!7!!!~!77!!!7JY5P5YYJY55YJ?77!!!7?7!!7YPBBBBB########\n"
                         "&###############################BGY7!!!!!!~~!!!!!!!!7!!!!!7JYYY???777???7!!!77!!!!7?Y5PGBGGPGGBB####\n"
                         "&&&&&&&&&&&&&&&&&&&&############BPJ7!!!!~~!!~~~~!!!!!!!7!!!!777!!!!777!!7777!!!777777?J555Y??J5GBB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&########BBGY?7!!!!!!!~!!!!!~!!!!!!!!77!!!77!!!!!77!!!7777!777???777777777JPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&########BGY7!!!!!!!!!!!!!!!!!!!!7!!!!!7!!!!77!!!!7777!!77!77777777!!7777?YGB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#####BBGY7!!~!!!!!~~!!!!!!!!7!!!!!77!!777!!!!777!!77777!77J?7!77777!77J5GB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&###G5J?7!~~~~~~~~~~~~~~~~~~~!!~~~!!!!!!!!!!!!!!!!!!!!77?JY5Y7!!!!!!!7J5GB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GJ77?JJ?77?JJ?777???77?JJ?777?J?7!77??7777??7777?JJ5GBBGY777?J?777JPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BBBBBBBBBBBBBGBBBBBBBBBBBBBBBBBGGGBBGGGBBBBBBBBB#######BBBBBBBBBB###\n";

            sleep(m_play_speed);
        }

        void frame58()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5YJ?J5YJ?JYY5PGPP5YJJJYYJ??JY5Y??JY5PPGGGGBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG5J?!!!!!7!!!!?J?7!!77!!!!77!!!!!!!~!7JYPGGBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "######################BBBBBBBBBBBBG5?7!!7!!~~!7!~~~!7!!!!!7!!!!77!~~!77!!!!?Y5GGGBBBB##BB###########\n"
                         "###############################BBBG5?77!!!!7!!~~!!!!!~!7!!~!777!!7JY?!!!77!!!!?JYPGBBB##############\n"
                         "#################################BG5?!!!7!!!~!!!!!!!7!!!!!77!7?Y5555YYJ?7!!77777!7?YGB##############\n"
                         "#################################BG5?7!!!!!!!!!!!!!!!!!!!!7?Y555YJ77???77777!!!777?JPGBBBBBB########\n"
                         "&&&&&&&&&&#&&#&&&#&##############BG5J7!!!~!!!~~!!!!!!!!7!!!7JJ?7!7777!!777!!!777!77JYPGGP55PGB######\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&#&########BGY7!!!!!~~~!!!!~!!!!~!!!7!!!!77!!!7777!!7777!!777777?J?777JYPB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#######BB5?77!~!!!!!~!!!!!~!!7!!!!77!!!!777!!7777!!777!!7JYJ7!!777!7?5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BG5?!!!!!!!~~!!!!!!!!!!!!!7!!!!777!!77!!!777!!!7?J55Y?7777!7?J5G##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BPYJ?7!!~~~~~~~~~~~~~~!!!!~~~!!!!!!!!!!!!7!!!!!!77?JY5?!!!!!!!7J5G##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##5?7?JJJ?7?JJ?77?J??77?J?777?J?777?J?77?J?????JJYPGBGP?77?J?77?YG##&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&########BB##BB####BBBBBBBBBBBBBBB#BBBB#BBBBB#########BBB###BB###&&&\n";

            sleep(m_play_speed);
        }

        void frame59()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPYJ??YYJ??JY5PGGGP5JJ?JYJ???J5PPGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBPJ?7!!!!7!!!!7JYPPYJ?7!!!!7!~!7?Y5PGBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "###########################BBBBBBBBBPJ7!!77!!~!!!!~~7?7!!!!77!!!777!!!?J5GBB#####################BBB\n"
                         "################################BBBBPJ?7!!!!77!~~!!!!~~!77!~~!77!!!7?7!!7YGB########################\n"
                         "##################################BBPJ7!!77!!!!!!!!!!7!!!!!7!!!!7777!!7?J5PGBB######################\n"
                         "##################################BBPJ77!!!!!!!!!!!!!!!!!!7!!!7777!7777!!!7JGBB##########BBB########\n"
                         "&&&&&&&&&&&&&&&&&&&&###############BGY?!!!!!!!!!!!!!!!!77!!!!77!!!7777!!7??JPGBB######BBGP55PGB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&########BGPY?!!!7!!~!!7!!!!!!!!!!777!!!7?7777777!!7JPGBBB###BG5Y?7!7J5GB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BGY?7777!~!!!!!~!!!!!~!!7!!!7??JJJJ?77!!777!!!?J5GB##PJ7!!777!7?PB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&####GJ?7!!!!!!!~~!!!!~!!!!!!!!7?JJJ??7!!777!!!777777YGBBPYJ?7!!77?YPB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BP?!~~!!~~~~!!~~~!!!~~!!!!~~!!7!!!!77!!!!77!!!77JYGBBP?7!!777!7JPB#&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##P?!!777!!!777!!777!!!777!!!777!!7777!!777!7!77??5BBB57!!777!!7YGB#&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BGGGBBGGGGBBGGGBBGGGGGBGGGGGGGGGGBGGGGBBGGGGGBB####BGGGGBBGGGB##&&\n";

            sleep(m_play_speed);
        }

        void frame60()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP5YYY5PPGGGGGGGGGPPP5YYYPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ?7777!77JYPPGGGPP5J???7!!7?Y5PGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ?7!!!!!!!~!?Y55?7777!!!!!7!!!7J5PGGGBBBBBB##BB#BBBBB#########\n"
                         "############################BB#BBBBGP5?7!!!!!~!!!!!!!77!!!!!77!!!!77!!!7J5PGBBBBB###################\n"
                         "################################BBGJ7!!!!!~!!!!!!!!!7!!!!!!!!!!7!!!!!777!!7?YPGBBB##################\n"
                         "#################################BGYJ7!!!!!7!!!!7!!!!!!!!!!!77!~!!77!!!77777!?YPBBB#################\n"
                         "#################################BGJ7!!!7!~~!!!!!!!77!!!!!7!!!!7?7!!!7?7!!!77JYPGBBBBBBGGGGBB#######\n"
                         "#################################BPJ?7!!!!!!!~~~!7!!!!77!!!!7?????J?J????77!!7?Y5PGGGGPYJJJY5PGB####\n"
                         "&&&&&&&&&&&&&&&&#################BP?!!!!!!!~~!!!!~!!!!!~!!7!!!?Y5YJJJJ?77!!7777!7?JY5YJJ?77!77J5GB##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&#########BPJ7!!!!!!!!!!!!!!!!!777!!!7?J555J??7!7777!!!77777?Y5Y7!!7777!7YPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&####BP5J7!!!!!!!!!!!!!!!!!!!!!!!77!!7777!!7777!!777!!!77J555J?7!!!7?J5PB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&###PJ7!!!!~~~~~~~~~~!!!~~!!!!!~~!!!!!!!!!!!!!77!!!!777!?Y5J7!!777!!7YPB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##P?!77??7!77?7!!!777!!7777!!!777!!!777!!!777!!777777?J55?7!777!!7?5G##\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BBBBBBBGGBBGGGGGGGGPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBGPPPGGGPPGB##&\n";

            sleep(m_play_speed);
        }

        void frame61()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP55PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGGGGPGGGGGGGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPPP55YJ??JJ55PGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGPYY?7!!!!!!!!7?J5PGGGGGGGPPPPGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
                         "########################BBBBBBBBBBBGPJ!!!!!!!~~!77!!!!?J5PPP5YJ?7?J5GBBBBBBBBBBBB###############B###\n"
                         "###########################BBBBBBBGGPYJ?!~~~!7!~~~!777!!!?J?7!!7?J5PGGBBBBBB########################\n"
                         "##############################BBBG5YJ7!!~!7!~~~!77!!~!77!~!!7?7!!!7?Y5GGBBBB########################\n"
                         "##############################BBBPJ!!!77!!~~!7!!~~!77!!!!77!!!!7?7!!!7?Y5PGBBB######BBBB############\n"
                         "##############################BBGPY?7!~~~!7!!~~!77!~~!777!!!7?7!!!!777!!7?JYPBB####BGGP5PPBBB#######\n"
                         "&&&&&&&&&&&&&&&&&&###########BGY?7!!~~!!!~~~!!7!~!!77!!!!77!!!!!77!!!!7?77!?YPBB###BG5YJJ?J5PBB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&#######BGPJ!!~!!!!~!!!!!~~!!!!~!!!7!!!!!77!!!7??7!!!7?Y5GBB###G5YJ?!!!!?J5GB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&######GPPJ77!!!!!!!!~!!!!!~~!!7!!!!!7!!!!7777!!!777!7?YPBBBBBBY?7!!777!7JPB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&#####P?7!!!!!!!!!!~!!!!!~!!!!!!!!!!!!!!777!!!777!!!7?J5PBBBBBGY??777!77?YPB##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&###BP?!~~~~~~~~~!!~~~~!!~~~~!!!~~!!!!!!?Y5Y?7!!777!!!7?YPBBBGY7!!!77!!7YPB##&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&##P!~!777!~~!7!!~!!!!!~!!!7!!!!777?YPGGBBGG5J7!!!77??J5BBBP?!!777!!!?YG##&&\n"
                         "@@@@&&&&&&&&&&&&&&&&&&&&&&##BGGGGGGGPPGGGPPGGGGGPPGGGGPPGGGBBB########BGGPPGBBB####BGPPGBBGGGGB##&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###################################&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";

            sleep(m_play_speed);
            // end of lick
        }

        void frame62()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBGP5Y?7!77??7777?J55YJ?7!!!!77!!!!777!!!7?Y5PGGGBBBBBBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGY?7!77!!!!!!!!!~!77!!~!!!!!!!!!!!!!!!!!!!7?J5PGBBBBBBBBBBBBBBB#####\n"
                         "############################BBBBPJ77!!!!!!!!!~!!!!~~!!!!!~!!!!7!!!777!!!!77!!!7JYPGGBBBB############\n"
                         "##############################BBPJ7!~~!!!!!!!!!!~~!!!!!!!!!77?JJ?7!!77?7!!!!77!!!7?Y5GBB############\n"
                         "###############################BGY777!!!~!!!!!!!!!!!~!!!!!!!7JY5PP5Y??77!77!!!!777!!7JPBB###########\n"
                         "###############################BBPYJ7!!!!!!~~!!!!!~~!7!!!!!7JYPPGGGGPY?77!!!777!!!77?YPGBBBBB#######\n"
                         "################################BBBPJ?!!~~!!!!~~~!7!!!!!7!!!!7?Y5PPP5J7!!777!!!7777!7J5PGGGGGGGBB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&##########BPJ!!!!!!~~!!!!~~~!!!!!!!!!!!!7?JYYJ?77!!!777!!777?Y55JJJJY555PGB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&######BBGPJ7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!77!!!7777!!!77777?JJ77!!7?JY5PGB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###G5J?7!!!~!!!!~~!!!!~!!!!!!!!!!!!!!!7!!!!7777!!7777?Y5YY?7!!77!!!7JPB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##GJ7!!~~~~~~~~~~~~~~~~~~~~~~~~!!~!!!!!!!~!!!!!!!!!7JPGGGJ!!!!!!!!7YPB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#P?77?JJ?77?JJ?77?J??7??JJ????JJ???JJJ?7??JJ?77?JJYPBBBGY?7?JJ???J5G#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BB###BBBBB#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB##########BBBBBBBB##&\n";

            sleep(m_play_speed);
            frame63();
        }

        void frame63()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP55PPPPP555555PPPPPPPPPPPPPPPPPPP555PP55PPPPPPPPPPPPPPPPPPGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP5YJJJJYYJJJY5PPPP55YJ?JYYJJ?JJYJ???JY5PGGGGGGGGBBBBBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBY7!!!7!~~!777!!!JJ?!!!!7!~~!77!~~!77!~!7JYPGGBBBBBBBBBBBBBBBBBBBB\n"
                         "######################BBBBBBBBBBBBG5J7!!~!!7!~~!!!!~~!77!~~!77!~~!77!~~!77!!!?5GBBBBBB##############\n"
                         "###############################BBBGY7!~!!!!!!!7!~~~!!!~~!7!!~!7J?7!!!?7!!!!7?Y5GGBBBBB##############\n"
                         "#################################BB5?7!!!!!!!!!!!!!~~~!!!!~!7?JYPPPY?7!777!!7J5GBBBBBBB#############\n"
                         "#################################BB5?!!!!!!!~!!!!~~!!!!!!!7!!7?YPGGPY?777!!7?Y5GGGGPPGBB############\n"
                         "##################################BPYJ?7!!!!!!!~!!!!!~!7!!!!7?J5PPP5J?7!7777777?JYY?7?YGB###########\n"
                         "&&&&&&&&&&&&&&&&&&&&&#############BG5J?!!!!!!!!!!!!!!!!!!!!!!!!!7?Y5PP5J7!!77777!!777?YGBB#BBB######\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BBG5?!!~~!!!!!!!!!~~!!!!!!!777!77JYY?7!777!!7777!7?YPGBGP5PPGB###\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####BP5Y?7!!!!!~~~!!!~~!!7!~~!77!!!!77!!!7777!!777!!7?JJY555YJ777J5GB#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###BY!~~!7!~~~!!!~~~77!~~!77!~~!77!!!!77!!!7?7!!!7?J5P5YY?!!7??!!!?5B\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BJ!~~~~~~~~~~~~~~~~~~~!~~~~~!~~~!!!!~!!!!!!~!!!!7YPJ7!!!!!!!!~7JPB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&BPYY5555YJY555YYY55YJYY5YYYYY55YYY555YYY555YYY5PPGBBBP5YY5P5YJY5B#\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#####################################################&####&&\n";

            sleep(m_play_speed);
            frame64();
        }

        void frame64()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555P55555PPPPPP5555555555P55Y55PPPPPGPPGGGGGGGGGGGGGGGGG\n"
                         "GGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGYJ??7777????7?Y5YJ??77!7777!!7777!7?J5PGGGBBBBBBBBBBBBBBBBBB\n"
                         "BBBB#######################BBBBBBBBBBBBGY7!~!!!!!!!!!!~!!!!!!!!!!!!!!!!!!!!!!!7YGBBBBBBBBBB#########\n"
                         "####################################BBBGJ!!!!!!!!!!!~~!!!!!!!!!!!7?7!!!77!!!77JYPGBBBB##############\n"
                         "######################################BGJ7!!!!!!!!!!!!!!~!!!!!!77JYYYJ?7777777?YPGGGBBB#############\n"
                         "######################################BGY7!!!!!!!!!!!!!!!!!!!!77?J555Y?7777777?Y55555PGB############\n"
                         "######################################BB5?77!!!!!!!!!!!!!!!!!7!77JY5YYJ??7!777777??J?7?YG###########\n"
                         "&&&&&&&&&#######BBP55PGB###############BPY?7!!!!!!!!!!!!!!!!!!!77!77??JYYJ77!!7777!77?J5GBBBBBBBB###\n"
                         "&&&&&&&&&&&&#BGPY?JYYJJJ5GB###########BBPYJ?7!!~!!!!!!!!!!!!!!!!!!77777777!777!!7!!777?YPGPPYJJYGBB#\n"
                         "&&&&&&&&&&BP5Y?JY5PGBGP5??JY5GB########G?!!!7!!!!!!~~~!!!~~!7!!!!!!!!!!7!!!7777!!77?YP55YJ777?7!7?5B\n"
                         "&&&&&&&&&#PYY5GBB#######BG5JJYPB#&&&###P?~~~!!~~~!~~~~~!~~~!!!~~!!!!!!!!!!!!!!!!!!!7YPY7!!!!!!!!!JPB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&###&&&&&&&&#G5YY555YJY55YJYY55YYY5YJJYYYYJJYYYYJY55YJYY5PGBBG5YJY55YJJYG#\n";

            sleep(m_play_speed);
            frame65();
        }

        void frame65()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPY??JJJ????JY5PPGGGGGGGGGGGGGGP5YJ?JJYJ?7?JY55PGGGGGBBBBBBBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPY?7!~~!!7!!!!?J5PPP5Y5PGP5555PPYJ?7!!!!77!~!7J5PGBBBBBBBBBBBBBB\n"
                         "##############BBB###########B###BBBG5?!~!!7!~~!77!!~!?J?!~!7YJ7!!7JJ7!!!777!~!7?7!~!?5GBBBBB########\n"
                         "#################################BBGPY?7!~~!!!!!~!77!~~~!7!~~!7??!~~!77!!~!777!7?JJY5PGBBB##########\n"
                         "################B#######BBBB######BB5?!~!!7!~~~!77!~!!77!~!?JY5P5J?7!!!!77!!!7JY5PGPYY5PGB##########\n"
                         "##########BBGBBBGGBBBBGGBBBBB#####BBBG5J7~~~!!!!~~!7!!!!!7?YPGGG5?!!!77!!!!7?J5GGGGY777?5B##########\n"
                         "&#######GY??JYPY77?Y5Y77?YPGBBBB##BBBBBPJ77!!~!!77!~!!!!!~!?YPPGGP5J7!!777777?YPGGP5JJJ5GGB#########\n"
                         "&&&&&###PY?7?Y5Y?!7JPY7!~~!7J5BB######BP?~~~!7!!~~!7!!~~!7?J5PPPGGGPY?77!!!7?Y5PPGPJ7777?YPBB#######\n"
                         "&&&&&&&&########BBBBBBBGJ7!7?5GB######BPJ77!!!!!!!!!!!!!!!!77?Y5PGG57!!!777!!!?JY55Y??777?YGB#######\n"
                         "&&&&&&&&&&&&&&&&&######B5!!7J5GGB#####BP?!!!!!!!!!!!!!!!!!7!!!!7?YPY?777!!!77777!7777!!7?J5GB#######\n"
                         "&&&&&&&&&&&&&&&&&&&&&##BPJ7!!!7J5BBBBG5Y?!!!!!!!!!!!!!!!!!!~!!!7!!7!77!!!777!!!777!!77777?YGB#######\n"
                         "&&&&&&&&&&&&&&&&&&&&&&#B5?7!~~!?YBBB57!!~~~~~!~~~~~!!~~~~!!~~!!!!!!~!!!!!!!!7!!!!777!!!77JY5GBBGPPGB\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&#BPY?77?YPB##G5J?7!!7777!!777!!!777!!!777!!!777!!!7777!!7?77!!77??777J5PJ7!?P\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#######&&&&##BBGGGBBGGGGGBGPPGGGGGPPGBGGPPGGGGPGGBGGPGGBBGGGGBBGGGGBBGGGGB\n";

            sleep(m_play_speed);
            frame66();
        }

        void frame66()
        {
            m_frame++;
            clearConsole();

            std::cout << "PGGGGGGGGGGGGGGGGGGGGGGGGGGPPPPPPPGGGPPP555555555555PPPPPPPPPPPPPPPPPPPPPPPGGPP5YY5PP5YY5PGGGGGGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ7!!77777!!7?Y5PPGGGPGGGGGPPPPGGP55J??777!!77777JYGGBBBBBBBB\n"
                         "################BBBBBBB######BBBBBBBBBG5?77!!~!!!!!!~!7?J55J??J5PYJ?JY55J?77!!!!77!!!!7?J5GBBBBBBBBB\n"
                         "###################################BBBG5?!~~!!!!~!!!!!!!!!77!!~!77!!~!!7!!!!!!77!!!777!7?YPGBBB#####\n"
                         "################BBGGBBBBBBB#########BBGY7!!!!!!!!!!!!!77!!~~!7!!~~!77!!~!!77!!~!7?7!!!77J5PGBBB#####\n"
                         "##############BGPY??JYPGBBBBBB######BBG5?!!~~!!!!~!!!!!!!!7!!!7??J7!!!!7!!!!!7777?Y55J77?J5GBBB#####\n"
                         "&&&&&########G5?7????!!?YPGGBBBB#BBBBBG5?!!!!!~!!!!!~~!!!!!?Y55JJ????7!!!777!!7?J5PP5YJJY5PGBBB#####\n"
                         "&&&&&&&&&&&##BG5Y5GBB5YJ???J5GBBBBBBBBB5?!!~!!!!!!!!!!!~!!7JYPGGP5?77!7!77!!!7?JY5PGPY?7777J5GB#####\n"
                         "&&&&&&&&&&&&&&&&#######BG5J??JY5PGBBBBBPYJJ7!!!!!!!!!~!!!!!7?J5PP5J?77!!!!7777??JYPG5J??777?5GB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&####BG5YJ??Y5GBBBPYJ?!!~!!!!!!!!!!!!7?JJY55Y?77!!777!!!7??JYPP5J?7777J5PGB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&#BBGPYYYPBBBBY7!!!!!!~!!!!!!!!7777?JYYYJ??777!!!!777!!!?Y5YJ?7??77?J5G####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&#BGPPYJJY5BBBG5?!!~~~!!!!!!!!!!~!!7??7!!!77!!!!77!!!7777!!7777777?JJY5G####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&#BPYJJJJYPBG5?7!~~~~~~~~~~~~~~~~~~~~!~~~!!!!!!!!!!!!!!!!!!!!!!7!!7J5PB###&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&##GP555PGBPJJJJJ?777???7777??7!!77?7!!!7777!77??7777???777?J?7!7?YPGB##&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###########BBBBBBBBGGBBBGGGGBBGGGGGBBGGGBBBGGGGBBBGGGBBBGGGBB###&&&&\n";

            sleep(m_play_speed);
            frame67();
        }

        void frame67()
        {
            m_frame++;
            clearConsole();

            std::cout << "BBBBBBGGGGGGGGGGGGGGBBBBBBBBBBGGP5Y?777?JJJJJJY55PGGGGGGGGGGGGGGGGGGGGGGGGGGPYYJJJJJ?7777?5PGGGBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPYJJ??7!~~!!7???JJYPGGGGP5555PPP5Y55PPP55Y5PPPYJJ?!~~!7????JY5GBBBBBB\n"
                         "############################BBBGP5?!~~!77!!~~!?JJY5PP5YJ7!~!?Y?!!!7?Y?7!!!?YJ7!!!777!~!!?JY5PGBBB###\n"
                         "#############################BBBBG5J7!!~~!!!!!~~!?YY?!!!!77!~~!!7!!~~!!77!!~!!77!~~!77????JY5GBB####\n"
                         "##############################BBBGJ!~~!!!!~~!!!!!!!!777!~~!!77!~!!!777!!!!77!!!77777!!!!?JY5PGBB####\n"
                         "##############################BBBG5J77~~~!!!!~~!!777?Y55Y?7!!!7777!~!!777!!!77??!!777777?JY5GBBB####\n"
                         "&&&&&&&&&&####################BBBPJ!!!!!!~~~!!!!!!!7JYPP5YYJ?7!!7777!!!!!777?JY55J?7!!77JYYPGBB#####\n"
                         "&&&&&&&&&&&&&&################BBBGY?7!~~!!!!!!!!!!!7?Y5PP5Y???777!!!!!777?J5PGGGP5YJ??7777?J5GB#####\n"
                         "&&&&&&&&&&&&&&&&&##############BBPJ7!!!!!!~!!!!!!~!7?YPGPPPY?77!7777!!!77JYPGGGGP5J?777777?J5GB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&#########BBGY?7!!~~!!!!!!!!!!7JYPGGP5J?777!!!!777!!77JYPPPP5YJ?77!77?YPGBB####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&######BBBPJ7!!!!!~~!!!!!!!!7JY55PP5J?7!!777!!!!77??JYY5P5YJJ????777?YPB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&######BBBPJ7!~~!!!!!~!!7!!!~~!7?Y55J??77!!!777!!!!7?JY55YJJ?7!!!7?JYPGB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&####BG5J?7!!!~^~~!!~~~~!!!!~~~!77!~~~!77!~~!!777!!!7??7!!!77??!!!?YGB####&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BP?!~~!~~~~~~!~~~~~~~~~~~~!~~~~~~!!~~~!!!!~~~!!!!!!~~!!!!~~!!?YPGB##&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BP555PPP5YYY5P55YYY5P5YYYY555YYYY555YYYY5P5YYYY5P5YJJY555YJYYPBB##&&&&\n"
                         "@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#############################################################&&&&&&\n";

            sleep(m_play_speed);
            frame68();
        }

        void frame68()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPP5555555555555555555555555555555555555555555PPPPPPPPPPPPP55PPPPPPPPPPPPPPPPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGPGGGGGGGPP55YYJY55PPPPPPGGPPPPPPPGGGGGGGGGGGGGGGGGGGGPPPPP5YJJJY5PPGGGGGGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ7!7777!!7?Y5PPGGGGGGGGGPPPPGGPPPPPGGPPPPPGGP55J?7!!77!!!7J5GBBBBBBBB\n"
                         "#############BBBBBBB########BGPY?7!!!!!!!!!!7JY55PGP55Y777?Y5J?77?YYJ777JYY?77777!!!!!77?J5GBBBBBBBB\n"
                         "############################BBPY???7!!!~!!!!!!!!?YY?!!!!!!~~!!!!!~~!!77!!!!777!!!!777!!!7J5GBBB#####\n"
                         "##############################BPYJ7!!!!!!!!!!77!!!!777!~!!!!7!!!!!7!!!!7??7!!!!777!!!77?JYPBBB######\n"
                         "###############################BBG5?7!~~~!!!!!!!7??JYPPY?7!!!!!7!!!!!77?Y5P5Y?7!!77777!7?YPBBB######\n"
                         "&&&&&&&#######################BBBPJ!~~!!!!~~!777JYPPGP5?7!777!!!!!77!!!7J5PGGG5J?7!!77?Y5PGBB#######\n"
                         "&&&&&&&&&&&&&&&&###############BBG5?7!!~~!!!!!!!7Y5GGGPY?7!!!!777!!!!7??Y5GGGPJ7!!7??YPGGBBB########\n"
                         "&&&&&&&&&&&&&&&&&&&&&##########BBPJ!~~!!!!~~~!77JYPGGG5J?77777!!!777!!!7?5GGGG5J?7!!!7?J5GBB########\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&########BBGY?77!~~~!7!!~!7YPGGGPY?77!!!!77!!!!7?JYPGGGPJ77!7777!!7JPB########\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&######BBBPJ!~~~!!!~~~!7?JY5GGG5?!!!777!!!!77!!!!?JY5PP5J??!!!7?JY5GB######&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&####BGPYJ77!~~~~!!!~~~!7?Y5P5J77!~~!777!~~!7777!77J?7!!777?7!!7YPB#####&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BPJ!~~!!~~~~~~~~~~~!!~~!77!!~~~!!!~~~~!!!~~~!77!!!!!!!!~!!7J5GB##&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BPP5PPPPP555PPP5YY5PP5YY5PPP5555PP55Y55PP5YY55PP5YY5PP5YYY5GB#&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######################################################&&&&&&&&&&&\n";

            sleep(m_play_speed);
            frame69();
        }

        void frame69()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPP5555555555555555555555555555555555555555555PPPPPPPPPPPPP55PPPPPPPPPPPPPPPPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGPGGGGGGGPP55YYJY55PPPPPPGGPPPPPPPGGGGGGGGGGGGGGGGGGGGPPPPP5YJJJY5PPGGGGGGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ7!7777!!7?Y5PPGGGGGGGGGPPPPGGPPPPPGGPPPPPGGP55J?7!!77!!!7J5GBBBBBBBB\n"
                         "#############BBBBBBB########BGPY?7!!!!!!!!!!7JY55PGP55Y777?Y5J?77?YYJ777JYY?77777!!!!!77?J5GBBBBBBBB\n"
                         "############################BBPY???7!!!~!!!!!!!!?YY?!!!!!!~~!!!!!~~!!77!!!!777!!!!777!!!7J5GBBB#####\n"
                         "##############################BPYJ7!!!!!!!!!!77!!!!777!~!!!!7!!!!!7!!!!7??7!!!!777!!!77?JYPBBB######\n"
                         "###############################BBG5?7!~~~!!!!!!!7??JYPPY?7!!!!!7!!!!!77?Y5P5Y?7!!77777!7?YPBBB######\n"
                         "&&&&&&&#######################BBBPJ!~~!!!!~~!777JYPPGP5?7!777!!!!!77!!!7J5PGGG5J?7!!77?Y5PGBB#######\n"
                         "&&&&&&&&&&&&&&&&###############BBG5?7!!~~!!!!!!!7Y5GGGPY?7!!!!777!!!!7??Y5GGGPJ7!!7??YPGGBBB########\n"
                         "&&&&&&&&&&&&&&&&&&&&&##########BBPJ!~~!!!!~~~!77JYPGGG5J?77777!!!777!!!7?5GGGG5J?7!!!7?J5GBB########\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&########BBGY?77!~~~!7!!~!7YPGGGPY?77!!!!77!!!!7?JYPGGGPJ77!7777!!7JPB########\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&######BBBPJ!~~~!!!~~~!7?JY5GGG5?!!!777!!!!77!!!!?JY5PP5J??!!!7?JY5GB######&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&####BGPYJ77!~~~~!!!~~~!7?Y5P5J77!~~!777!~~!7777!77J?7!!777?7!!7YPB#####&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BPJ!~~!!~~~~~~~~~~~!!~~!77!!~~~!!!~~~~!!!~~~!77!!!!!!!!~!!7J5GB##&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BPP5PPPPP555PPP5YY5PP5YY5PPP5555PP55Y55PP5YY55PP5YY5PP5YYY5GB#&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######################################################&&&&&&&&&&&\n";

            sleep(m_play_speed);
            handleLook();
        }

        void handleLook()
        {
            frame70();
            frame71();
            frame72();
            frame73();
            frame74();
            frame75();
            frame76();
            frame77();
            frame77();

            
            frame73();
            frame74();
            frame75();

            frame1();
        }

        void frame70()
        {
            // start of looking
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPP5555555555555555555555555555555555555555555PPPPPPPPPPPPP55PPPPPPPPPPPPPPPPPPPPP\n"
                         "GGGGGGGGGGGGGGGGGGGGGGGPGGGGGGGPP55YYJY55PPPPPPGGPPPPPPPGGGGGGGGGGGGGGGGGGGGPPPPP5YJJJY5PPGGGGGGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ7!7777!!7?Y5PPGGGGGGGGGPPPPGGPPPPPGGPPPPPGGP55J?7!!77!!!7J5GBBBBBBBB\n"
                         "#############BBBBBBB########BGPY?7!!!!!!!!!!7JY55PGP55Y777?Y5J?77?YYJ777JYY?77777!!!!!77?J5GBBBBBBBB\n"
                         "############################BBPY???7!!!~!!!!!!!!?YY?!!!!!!~~!!!!!~~!!77!!!!777!!!!777!!!7J5GBBB#####\n"
                         "##############################BPYJ7!!!!!!!!!!77!!!!777!~!!!!7!!!!!7!!!!7??7!!!!777!!!77?JYPBBB######\n"
                         "###############################BBG5?7!~~~!!!!!!!7??JYPPY?7!!!!!7!!!!!77?Y5P5Y?7!!77777!7?YPBBB######\n"
                         "&&&&&&&#######################BBBPJ!~~!!!!~~!777JYPPGP5?7!777!!!!!77!!!7J5PGGG5J?7!!77?Y5PGBB#######\n"
                         "&&&&&&&&&&&&&&&&###############BBG5?7!!~~!!!!!!!7Y5GGGPY?7!!!!777!!!!7??Y5GGGPJ7!!7??YPGGBBB########\n"
                         "&&&&&&&&&&&&&&&&&&&&&##########BBPJ!~~!!!!~~~!77JYPGGG5J?77777!!!777!!!7?5GGGG5J?7!!!7?J5GBB########\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&########BBGY?77!~~~!7!!~!7YPGGGPY?77!!!!77!!!!7?JYPGGGPJ77!7777!!7JPB########\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&######BBBPJ!~~~!!!~~~!7?JY5GGG5?!!!777!!!!77!!!!?JY5PP5J??!!!7?JY5GB######&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&####BGPYJ77!~~~~!!!~~~!7?Y5P5J77!~~!777!~~!7777!77J?7!!777?7!!7YPB#####&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&#BPJ!~~!!~~~~~~~~~~~!!~~!77!!~~~!!!~~~~!!!~~~!77!!!!!!!!~!!7J5GB##&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&##BPP5PPPPP555PPP5YY5PP5YY5PPP5555PP55Y55PP5YY55PP5YY5PP5YYY5GB#&&&&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######################################################&&&&&&&&&&&\n";

            sleep(m_play_speed);
        }

        void frame71()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGPGGGGGGGGGGGGGGGGGGGPP55YY5PPPPPPPPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPP5YYYY5PPGGGGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGPJ77777!!7?J5PPGGGGGGGGGGGPGGGGPPPGGGGPPPGGGPP5Y?7777!!!7J5PGBBBBB\n"
                         "###############################BBGPJ7!~!!!!!~~!7JY5PPGGPP5J???Y5Y???J55J???Y5YJ?77!7!!!!!!7?YPBBBBBB\n"
                         "################################BBPY??7!!!!!7!!!!!7?Y5Y?77!!!~!!77!~~!7!!!!!777!!!!7777!!77J5GBBB###\n"
                         "###############################BBBG5J?!!!!!!!!!!!!!!!777!!~!77!!!!!!!!!!!7777!!!77!!!!77777J5GBB####\n"
                         "######&&&&&&&##################BBBBBBGY?7!~!!!!!!!!7777?55Y?!!!77!!!!!!!77?J55J?7!77777!!7?JPGBB####\n"
                         "#####&&&&&&&&&&&&&##########BGGGBBGGGPJ!!!!!~~~!!77?J5PPG5J?777!!!!777!!!7?YPGGGPY?7!!7777?JPBBB####\n"
                         "#&&&&&&&&&&&&&&&&&&&####BGP5J!!!?YY7!!!!!!~~!!!!!!7?YPGGGPY?7!!!77!!!!!!77?YPGGG5J?7777?YPGBBBB#####\n"
                         "&&&&&&&&&&&&&&&&&&&&&##BG?~~!77!~~!!77!!!!!!!~~!!77?YPGGGPY??777!!!!77!!!7?YPGGGPJ?7!77?Y5GBBB######\n"
                         "&&&&&&&&&&&&&&&&&&&&&##BGY?7!!!777?JYPY77!~~~!!!!~!7YPGBGP5J?7!!!!77!!!!77?YPGGG5?77777!!7?5GB######\n"
                         "&&&&&&&&&&&&&&&&&&&&#BPYJ7~~!??YPGGBBP?!~!!!!~~!!77?Y5PGG5?7!!!!!!!!777!!!?Y5PGP5J?7!!!77?JYPB#####&\n"
                         "&&&&&&&&&&&&&&&&&&&&#P7~^!7?JPGBBBBBBGY7!!~~~!!7!!!7?Y5PGPY?7!!!!77!!!!!77777JYYJ?777777!7?5PB####&&\n"
                         "&&&&&&&&&&&&&&&&&&&&#P?!~7JPG#####BPJ7!~~~~~~~~~~~~~~~!7??7!!!~~!~!!!!!!~!!777!!!!!!!!!!!!?YGB###&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&#GJ?JYPB######B5JJJYYJ?7??J??77?JJ?77??J??77?JJ??7?JJJ?7??JJ?77?JJ?77?J5GB#&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&##&&&&&&&&#######BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGBBBBBBBB###&&&&&&\n";

            sleep(m_play_speed);
        }

        void frame72()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPGGPPPPPPPPPPPPPPPPPPPPPPPPPP5555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGPPP5555PPPPPGGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGG5J??7777?Y5PPGGGGGGGGGGGGGGGGGGGGGGGGPGGGGGPP5YJ?7777?JYPGGBBBBB\n"
                         "BBB###########################BBBBBPJ!~~!!!!~~!7JYPPPGGGGP5YJJYPPYJJY5P5JJJ555YJJ?!!!!77!!!7YPBBBBBB\n"
                         "#################################BBG5?77!~~!!!!!!!7?J55Y???!!~!7?7!~!!77!!!!7?7!!!777!!!!7?J5GBBBB##\n"
                         "#################################BBG5?7!!!!!~~!!7!!!!7?7!!~~!7!!~!!7!!!!!77!!!!77!!!!!777!7?5GBBB###\n"
                         "#################################BBBBGGY7!!~!!!!!!!77!!7J5Y?!!!77!!!!!7!!!7?YY?7!!7777!!!7?YPGBB####\n"
                         "######&&&#&&#####BGGGBBBGGGBBBBBBBBBBBGJ7!!!~~!!!!!!?Y5PPP5J?77!!!!77!!!!7?YPGGP5J77!777777J5BBB####\n"
                         "###&&&&&&&&&&###P?!!7Y5J7!7Y5P5YY5PGBBGY7!~~!!!!!!!7J5PGGG5J7!!!7!!!!!77!77J5GGGPJ?77!7?J5PGBBB#####\n"
                         "&&&&&&&&&&&&&##BPJ!7!~!!77???YY55555PGGJ7!!!!!!!!!!7?YPGGG5Y??77!!!!!7!!!7?Y5GGGPY?7!77?YPGBBB######\n"
                         "&&&&&&&&&&&&#BPYJ7!!!77?JJY5PPGGBBGGGGG5?7!~~!!!!!~!?YPGBGPY?77!!!!!!!!!77?J5GGGPJ?7777!!7?5GB######\n"
                         "&&&&&&&&&&&&B5!~!7?JYJJY5PGB#########BGY!~!!!!!!!!77?YPGGGY?!!!7!!!!!77!!!7J5PGGPY?77!!77?JYPB######\n"
                         "&&&&&&&&&&&#B5?77JYPPYY5PGB########BBBGY7!!~~~!!!!!!7?Y5PG5J77!!!!77!!!!77777?YYY?777777!7?5PB####&&\n"
                         "&&&&&&&&&&&&B57!~~!77?JYPB###&&&&##BPJ7!~~~~^~~~~~~~~~~!7??!~~~~~~~!~~!!!!!!777!!!!!!!!!!!?YPB###&&&\n"
                         "&&&&&&&&&&&&&#BGP5555PGB#&&&&&&&&&##PYYYYYJ???JJJ???JYJ????JJJ???JJJ???JJJJ??JJJJ???JJJ???J5GB#&&&&&\n"
                         "@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#######BB###BBB####BBBBB##BBB#BBBBBBBBBBBBBBBBBBB#BBBB###&&&&&&\n";

            sleep(m_play_speed);
        }

        void frame73()
        {
            m_frame++;
            clearConsole();

            std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPPP5YJJY5PPPPPPPPPGGGGGGGGGGGGGGGGGGGGGGGGGGPP55JJJYY5GGGGGGG\n"
                         "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG57!!!77!!7?Y5PGGGGGGGGPP5PPGGP5PPGPP55PGPP55J77777!!!7J5GBBBB\n"
                         "#####B###############################BG5J77!~~!!!!~!7JY5PGP55J7!!?YJ7!!?YJ777?JY?7!!77!!!!77?YPGBBBB\n"
                         "#####################################BB5?7!7!!!~~!!7!!!7JJ7!!!!!!~~!!7!~~!!77!!!!77!!!!777!!7J5GBB##\n"
                         "#####################################BBGP5Y7!!!!!!!!!77!!!!?J7!!!!77!!!777!!!7JJ7!!!777!!!7?JYPBBB##\n"
                         "&&&####################################BBBP?77!~~!!!!!!7JYYPP5J?7!!!!77!!!!7?J5PPPYJ777777!!7JPBB###\n"
                         "&&&#########BGP5JY5GBB####&#&###########BB5?!~~!!!!~!!7J5PGGGY?!!!77!!!!777!7?5GGGPY??7!7?J5PGBB####\n"
                         "&&&&&######G?!!!7?JPB###&&&&&&&##########BP?7!!!!!!!!!!?YPGGG5Y??7!!!!!!!!!7?Y5GGGPJ77!77J5PGBBB####\n"
                         "&&&&&&&&#&#GY777?JYPB####&&&&&&&########BBP?!!!!!!!!!!!?YPGBG5J?7!!!!!!!!!!77J5GGGPJ?777!!!?JPGB####\n"
                         "&&&&&&&&&&#GJ7777JYPB####&&&&&&&########BBP7!!!!!!!!!!7?YPGGGY?!!!7!!!!!77!!7JYPPGPY??7!777?J5GB####\n"
                         "&&&&&&&&&&#GJ7!!!!?5G##&&&&&&&&&&&&&###BBG5?7!~~~~!7!~~!?J5PP5J7!!!!!7!!~!77?77?JYJ7777777!7?5GB###&\n"
                         "&&&&&&&&&&#GY7!~~~7YG#&&&&&&&&&&&&&&&##GJ7!!~~~~~~~~~~~!~~!!77!~~~~!!~~~!!!!!!!77!!!!!!!!!!7J5G###&&\n"
                         "&&&&&&&&&&&&#BGPPPGB#&&&&&&&&&&&&&&&&&#BPPPPP5YYYY55YYYY55YJJYYYYJJY5YYJJYY5YJJJYYYJJJY5YYJJYGB##&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##################################################&&&&&&\n";

            sleep(m_play_speed);
        }

        void frame74()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPGGPPPPPPPPPPPPPPPPPPGGGGPPP55Y55PPPPPPPPPPPPPPPPPPPPPPPPGGGGGPPPGPP5YY55PGGGGGGGG\n"
                         "GBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBP??777777?Y5PGGGGGGGGGGGGGGGGGGGGGGGGGGPP5J?777!7?YPGBBBBB\n"
                         "BB########BBBB#################B#######BBB5?!!~!!!!!!7JYPPPGPP5J77J5Y?7?Y5Y???Y5Y?777!!!!!!7J5GBBBBB\n"
                         "###########BB###########################BBP?777!!!!!!!!!!?YY?!!!!!~!!7!!~!!77!!!!!!!!!!77!!!?5GBBB##\n"
                         "###########BB############################BG5J?!!!!!!~!!!7!!7!77!!!!!!!!!77!!!77?7!!!77!!!!7?YPGBB###\n"
                         "###########BB#############################BBBP?7!~~~!!!!!7?JY5PY?7!!!!77!!!7?J5PPYJ?777777!7?PBBB###\n"
                         "&&&&&#####BBGBBB##########################BBB57~~!!!!~!77J5GGBPJ7!!77!!!!7777?YPGGPY?77!7?Y5PGBB####\n"
                         "&&&&&#####GY7??YPGB##########&&&&###########BP?7!!~~!!!!!?YPGBPYJ?!!!!77!!!7?J5GGGPJ7!!7?Y5GBBB#####\n"
                         "&&&&&&&#&#GY77!!!?5B########&&&&&&&&&######BBP?!!!!!!!!!7J5GGGPY?77!!!!!!!!!7?YPGGPY?777!!7?YGB#####\n"
                         "&&&&&&&&&#BJ!!!!7JPBB#######&&&&&&&&&&#####BB57!!!!!!!!!7?5PGG5J7!!!!!!!!!!!7?YPPGPJ?77!777?YPB####&\n"
                         "&&&&&&&&&##BG5?!!!7?Y5GB##&&&&&&&&&&&&&&##BBG5?!!~~~!7!!!7?Y5GPJ77!!!77!!!!7777?JYJ?777777!7YPB###&&\n"
                         "&&&&&&&&&&&&&##BPJ7!~~!YG#&&&&&&&&&&&&&&##BY7!!~~~~~~~~~~~~~!77!!!~~!!~~!!!!!!!77!!!!!!!!!!?YGB##&&&\n"
                         "&&&&&&&&&&&&&&&&&&#BPPPG#&&&&&&&&&&&&&&&&#BPPPPP5YYY55YYY555YJY555YYY55YYYY55YJJY5YYJY555YYYPB#&&&&&\n"
                         "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#############################################&&&&&&&\n";

            sleep(m_play_speed);
        }

        void frame75()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555PPPPPGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGBGGGGGGBBBBBBBBBBBBBBBGGYYJ????JYPPGGGGGGGGGGGGGGGGGGGGGGGGGGPPYY?7777?YPGBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBB###BBBBBBBBBBBBB#BBBP?!~~!!!~!7?Y5PGGGGPYJ?J55JJJ5PYJ?J55J?77!!!7!!!?5GBBBBBB\n"
                         "############BBB##########################BBPJ777!!!!!!!!7?J5Y?77!!!!77!!!!7!!!!77!!!!77!!!7J5GBBB###\n"
                         "#############BB###########################BGYJ7!!!!!!!!!!!!7!!7!!!!!!!!!7!!!7777!!!!!!!7777J5GBB####\n"
                         "############BBB############################BBBP?7!~~!!!!!!7?JYP5J7!!!!!7!!!77J5P5Y?77777!!7JPBB#####\n"
                         "&####&#######BB############################BBB57~!!!!!~!7?YPPGGY7!!77!!!!77!!?5GGG5J?7!7?JYPGBB#####\n"
                         "&&&&&&&####BPPPBB################&###########BP?7!!~~!!!!!?5GGG5Y?7!!!7!!!!7?YPGGGY?7!7?YPGBBB######\n"
                         "&&&&&&&&&&BJ!!7J5PGB##########&&&&&&#########BP?!!!!!!!!!7JPGBG5J?77!!!!!!!!7?5GGG5?777!!7J5GB######\n"
                         "&&&&&&&&&&#G5Y7~~!?YPGB#######&&&&&&#########BP?!!!!!!!!!7J5GGGY7!!!!!!!!!!!7J5PPPY??77777?YPB######\n"
                         "&&&&&&&&&&&&&#BPY7!!!7J5GB###&&&&&&&&&&&&###BBP?7!~~~!7!!!7JYPP5?7!!!!77!~!7777?JJ?777777!7YPB###&&&\n"
                         "&&&&&&&&&&&&&&&&#BG5?!~~~JP#&&&&&&&&&&&&&##B57!!~~~~~~~~~~~~~!77!~~~!!!~!!!!!!!7!!!~!!!!!!7YPB##&&&&\n"
                         "&&&&@&&&&&&&&&&&&&&&##BGGG##&&&&&&&&&&&&&&&#GPPGP5YY5PP5Y55P5YY5P55Y5555YY5PP5Y5PP5YY555YYYPB#&&&&&&\n"
                         "#######&#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########################################&&&&&&&&&\n";

            sleep(m_play_speed);
        }

        void frame76()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555PPPPPGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGBGGGGGGBBBBBBBBBBBBBBBGGYYJ????JYPPGGGGGGGGGGGGGGGGGGGGGGGGGGPPYY?7777?YPGBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBB###BBBBBBBBBBBBB#BBBP?!~~!!!~!7?Y5PGGGGPYJ?J55JJJ5PYJ?J55J?77!!!7!!!?5GBBBBBB\n"
                         "############BBB##########################BBPJ777!!!!!!!!7?J5Y?77!!!!77!!!!7!!!!77!!!!77!!!7J5GBBB###\n"
                         "#############BB###########################BGYJ7!!!!!!!!!!!!7!!7!!!!!!!!!7!!!7777!!!!!!!7777J5GBB####\n"
                         "############BBB############################BBBP?7!~~!!!!!!7?JYP5J7!!!!!7!!!77J5P5Y?77777!!7JPBB#####\n"
                         "&####&#######BB############################BBB57~!!!!!~!7?YPPGGY7!!77!!!!77!!?5GGG5J?7!7?JYPGBB#####\n"
                         "&&&&&&&####BPPPBB################&###########BP?7!!~~!!!!!?5GGG5Y?7!!!7!!!!7?YPGGGY?7!7?YPGBBB######\n"
                         "&&&&&&&&&&BJ!!7J5PGB##########&&&&&&#########BP?!!!!!!!!!7JPGBG5J?77!!!!!!!!7?5GGG5?777!!7J5GB######\n"
                         "&&&&&&&&&&#G5Y7~~!?YPGB#######&&&&&&#########BP?!!!!!!!!!7J5GGGY7!!!!!!!!!!!7J5PPPY??77777?YPB######\n"
                         "&&&&&&&&&&&&&#BPY7!!!7J5GB###&&&&&&&&&&&&###BBP?7!~~~!7!!!7JYPP5?7!!!!77!~!7777?JJ?777777!7YPB###&&&\n"
                         "&&&&&&&&&&&&&&&&#BG5?!~~~JP#&&&&&&&&&&&&&##B57!!~~~~~~~~~~~~~!77!~~~!!!~!!!!!!!7!!!~!!!!!!7YPB##&&&&\n"
                         "&&&&@&&&&&&&&&&&&&&&##BGGG##&&&&&&&&&&&&&&&#GPPGP5YY5PP5Y55P5YY5P55Y5555YY5PP5Y5PP5YY555YYYPB#&&&&&&\n"
                         "#######&#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########################################&&&&&&&&&\n";

            sleep(m_play_speed);
        }

        void frame77()
        {
            m_frame++;
            clearConsole();

            std::cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555PPPPPGGGGG\n"
                         "GGGGGGGGGGGGGGGGGGGGBGGGGGGBBBBBBBBBBBBBBBGGYYJ????JYPPGGGGGGGGGGGGGGGGGGGGGGGGGGPPYY?7777?YPGBBBBBB\n"
                         "BBBBBBBBBBBBBBBBBBBBBBB###BBBBBBBBBBBBB#BBBP?!~~!!!~!7?Y5PGGGGPYJ?J55JJJ5PYJ?J55J?77!!!7!!!?5GBBBBBB\n"
                         "############BBB##########################BBPJ777!!!!!!!!7?J5Y?77!!!!77!!!!7!!!!77!!!!77!!!7J5GBBB###\n"
                         "#############BB###########################BGYJ7!!!!!!!!!!!!7!!7!!!!!!!!!7!!!7777!!!!!!!7777J5GBB####\n"
                         "############BBB############################BBBP?7!~~!!!!!!7?JYP5J7!!!!!7!!!77J5P5Y?77777!!7JPBB#####\n"
                         "&####&#######BB############################BBB57~!!!!!~!7?YPPGGY7!!77!!!!77!!?5GGG5J?7!7?JYPGBB#####\n"
                         "&&&&&&&####BPPPBB################&###########BP?7!!~~!!!!!?5GGG5Y?7!!!7!!!!7?YPGGGY?7!7?YPGBBB######\n"
                         "&&&&&&&&&&BJ!!7J5PGB##########&&&&&&#########BP?!!!!!!!!!7JPGBG5J?77!!!!!!!!7?5GGG5?777!!7J5GB######\n"
                         "&&&&&&&&&&#G5Y7~~!?YPGB#######&&&&&&#########BP?!!!!!!!!!7J5GGGY7!!!!!!!!!!!7J5PPPY??77777?YPB######\n"
                         "&&&&&&&&&&&&&#BPY7!!!7J5GB###&&&&&&&&&&&&###BBP?7!~~~!7!!!7JYPP5?7!!!!77!~!7777?JJ?777777!7YPB###&&&\n"
                         "&&&&&&&&&&&&&&&&#BG5?!~~~JP#&&&&&&&&&&&&&##B57!!~~~~~~~~~~~~~!77!~~~!!!~!!!!!!!7!!!~!!!!!!7YPB##&&&&\n"
                         "&&&&@&&&&&&&&&&&&&&&##BGGG##&&&&&&&&&&&&&&&#GPPGP5YY5PP5Y55P5YY5P55Y5555YY5PP5Y5PP5YY555YYYPB#&&&&&&\n"
                         "#######&#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##########################################&&&&&&&&&\n";

            sleep(m_play_speed);
        }
    };
}

int main()
{
    CatAnimation::CatAnimator catAnimator;
    catAnimator.animate();
}
