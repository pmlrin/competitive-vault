#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

typedef enum { ROCK, SCISSOR, CLOTH, DISPLAY, HELP, QUIT } SelectType;

typedef enum { WIN, LOSE, TIE } ResultType;

class GameOfRockScissorCloth {
  private:
    int userWins, computerWins, ties;
    string selectNames[6] = {"石头", "剪刀", "布", "显示结果", "帮助", "退出"};

    SelectType getUserChoice() {
        int choice;
        cout << "请选择 (0:石头, 1:剪刀, 2:布, 3:显示结果, 4:帮助, 5:退出): ";
        cin >> choice;
        if (choice < 0 || choice > 5) {
            cout << "无效选择，请重新输入。" << endl;
            return getUserChoice();
        }
        return (SelectType)choice;
    }

    SelectType getComputerChoice() { return (SelectType)(rand() % 3); }

    ResultType judge(SelectType user, SelectType computer) {
        if (user == computer)
            return TIE;
        if ((user == ROCK && computer == SCISSOR) ||
            (user == SCISSOR && computer == CLOTH) ||
            (user == CLOTH && computer == ROCK)) {
            return WIN;
        }
        return LOSE;
    }

    void displayCountdown() {
        cout << "石头... ";
        // 简单倒计时
        Sleep(1000);
        cout << "剪刀... ";
        Sleep(1000);
        cout << "布... 出拳!" << endl;
    }

    void displayResult(SelectType user, SelectType computer,
                       ResultType result) {
        cout << "你选择了: " << selectNames[user] << endl;
        cout << "计算机选择了: " << selectNames[computer] << endl;
        if (result == WIN) {
            cout << "你赢了!" << endl;
            userWins++;
        } else if (result == LOSE) {
            cout << "你输了!" << endl;
            computerWins++;
        } else {
            cout << "平局!" << endl;
            ties++;
        }
    }

    void displayStats() {
        cout << "游戏统计:" << endl;
        cout << "你赢: " << userWins << " 次" << endl;
        cout << "计算机赢: " << computerWins << " 次" << endl;
        cout << "平局: " << ties << " 次" << endl;
    }

    void displayHelp() {
        cout << "游戏规则:" << endl;
        cout << "石头胜剪刀，剪刀胜布，布胜石头。" << endl;
        cout << "选择相同为平局。" << endl;
    }

  public:
    GameOfRockScissorCloth() : userWins(0), computerWins(0), ties(0) {
        srand(time(0));
    }

    void Game() {
        SelectType choice;
        do {
            choice = getUserChoice();
            switch (choice) {
            case DISPLAY:
                displayStats();
                break;
            case HELP:
                displayHelp();
                break;
            case QUIT:
                cout << "退出游戏。" << endl;
                break;
            default:
                displayCountdown();
                SelectType computer = getComputerChoice();
                ResultType result = judge(choice, computer);
                displayResult(choice, computer, result);
                break;
            }
        } while (choice != QUIT);
    }
};

int main() {
    GameOfRockScissorCloth game;
    game.Game();
    return 0;
}