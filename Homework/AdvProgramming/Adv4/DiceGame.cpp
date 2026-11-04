#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

enum GameStatus { WIN, LOSE, CONTINUE };

class DiceGame {
  public:
    DiceGame() : winCount(0), loseCount(0) {}
    void Run();

  private:
    int RollDice();
    void Help();
    GameStatus Game();
    int winCount;
    int loseCount;
};

int DiceGame::RollDice() {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    return die1 + die2;
}

void DiceGame::Help() {
    cout << "掷骰子游戏规则：" << endl;
    cout << "1. 初次掷骰，如果点数为7或11，玩家获胜。" << endl;
    cout << "2. 如果点数为2, 3, 12，玩家失败。" << endl;
    cout << "3. 其他点数作为目标点，玩家继续掷骰。" << endl;
    cout << "4. 若掷出目标点，玩家胜利；若掷出7，玩家失败。 " << endl;
}

GameStatus DiceGame::Game() {
    int sum = RollDice();
    cout << "首次掷骰点数: " << sum << endl;
    GameStatus status;
    int myPoint = 0;

    switch (sum) {
    case 7:
    case 11:
        status = WIN;
        break;
    case 2:
    case 3:
    case 12:
        status = LOSE;
        break;
    default:
        status = CONTINUE;
        myPoint = sum;
        cout << "继续游戏，你的目标点数是: " << myPoint << endl;
        break;
    }

    while (status == CONTINUE) {
        cout << "按Enter键继续投掷骰子...";
        cin.ignore();
        sum = RollDice();
        cout << "本次掷骰点数: " << sum << endl;
        if (sum == myPoint) {
            status = WIN;
        } else if (sum == 7) {
            status = LOSE;
        }
    }

    if (status == WIN) {
        cout << "你赢了!" << endl;
    } else {
        cout << "你输了!" << endl;
    }
    return status;
}

void DiceGame::Run() {
    srand(time(0));
    int choice = 0;

    do {
        cout << endl;
        cout << "请选择:" << endl;
        cout << "1. 获得帮助" << endl;
        cout << "2. 玩一手游戏" << endl;
        cout << "3. 退出游戏" << endl;
        cout << "请输入你的选择: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            Help();
            break;
        case 2: {
            GameStatus result = Game();
            if (result == WIN) {
                ++winCount;
            } else if (result == LOSE) {
                ++loseCount;
            }
            break;
        }
        case 3:
            cout << "游戏结束, 再见!" << endl;
            break;
        default:
            cout << "选择无效, 请重新输入。" << endl;
            break;
        }
    } while (choice != 3);

    cout << "游戏统计结果: 胜利次数 = " << winCount
         << " 失败次数 = " << loseCount << endl;
}

int main() {
    DiceGame game;
    game.Run();
    return 0;
}
