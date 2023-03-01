#include "libary.h"
void movement(Board &mB, Unit &enemy, Unit beTarget[], sf::Event event, sf::Vector2f mouse, int dB[], int count)
{
        int dummy = 0;
        /* Check Click and move */
        if (event.type == sf::Event::MouseButtonPressed)
        {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                        sf::FloatRect trackUnit = enemy.entity.getGlobalBounds();
                        if (trackUnit.contains(mouse) && !enemy.isMove && !enemy.kill)
                        {
                                enemy.isMove = true;
                                // enemy.canAttack = false;
                                std::cout << enemy.isMove << " " << enemy.kill << std::endl;
                        }
                        else if (trackUnit.contains(mouse) && enemy.isMove)
                        {
                                enemy.isMove = false;
                        }
                        else if (enemy.kill)
                        {
                                enemy.kill = !enemy.kill;
                        }
                        for (int i = 0; i < fields * fields; i++)
                        {
                                /* Move */
                                if (mB.boardSurface[i].getGlobalBounds().contains(mouse) && int(mB.boardSurface[i].getFillColor().a) != 0 && int(mB.boardSurface[i].getFillColor().r) == 101 && enemy.isMove)
                                {
                                        /* Unit Move */
                                        enemy.isMove = false;
                                        enemy.canAttack = false;
                                        enemy.firstMove = true;
                                        enemy.entity.setPosition(mB.boardPositions[i]);
                                        
                                        /* Default Board Update */
                                        int temp = 0;
                                        dB[enemy.position] = temp;
                                        dB[i] = enemy.moveType;
                                        enemy.position = i;
                                        enemy.target.clear();
                                        // std::cout << enemy.moveType << " " << i << std::endl;
                                        // std::cout << int(mB.boardSurface[i].getFillColor().r) << std::endl;
                                        break;
                                }
                                /* Attack */
                                for (unsigned int j = 0; j < enemy.target.size(); j++)
                                {
                                        // std::cout << enemy.target[j] << std::endl;
                                        for (int k = 0; k < count; k++)
                                        {
                                                if ((beTarget[k].position == enemy.target[j]) && (beTarget[k].position == i) && (beTarget[k].moveType != enemy.moveType))
                                                {
                                                        dummy = k;
                                                        // std::cout << dummy << std::endl;
                                                        // std::cout << beTarget[k].position << std::endl;
                                                }
                                        }
                                }
                                // sf::FloatRect trackTarget = beTarget[dummy].entity.getGlobalBounds();
                                if (mB.boardSurface[i].getGlobalBounds().contains(mouse) && int(mB.boardSurface[i].getFillColor().a) != 0 && int(mB.boardSurface[i].getFillColor().r) == 237 && enemy.canAttack)
                                {
                                        /* Unit Move */
                                        enemy.kill = true;
                                        enemy.isMove = false;
                                        enemy.canAttack = false;
                                        enemy.entity.setPosition(mB.boardPositions[i]);
                                        beTarget[dummy].entity.setPosition(0, 0);

                                        /* Default Board Update */
                                        int temp = 0;
                                        dB[enemy.position] = temp;
                                        dB[i] = enemy.moveType;
                                        enemy.position = i;
                                        enemy.target.clear();
                                }
                        }
                }
                else
                {
                        enemy.isMove = false;
                        enemy.canAttack = false;
                }
        }
}