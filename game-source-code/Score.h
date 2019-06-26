/**
 * @class Score
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file Score.h
 * @brief This class is reponsible for managing the game's scoring system.
 */

#ifndef SCORE_H
#define SCORE_H

#include "DataTypes.h"
#include <fstream>

class FileCannotBeOpened{};

class Score
{
public:
	/**
	 * @brief Default constructor.
	 * @details Creates an instance of the class and initialises all relevant parameters.
	 */
	Score();
	
	/**
	 * @brief Update score.
	 * @details This function updates the score during gameplay.
	 * @param item identifies the object killed by the player.
	 */
	void updateScore(ID item);
	
	/**
	 * @brief Write score.
	 * @details This function save the score to a file if it is a new high score.
	 */
	void WriteScore();
	
	/**
	 * @brief Get score.
	 * @details This function returns the current score.
	 * @return Current score.
	 */
	const int getScore() const;
	
	/**
	 * @brief Get the high score.
	 * @details This function returns the high score.
	 * @return The high score.
	 */
	const int getHighScore() const;
private:

	std::string _filename;
	std::ifstream _infile;
	int _score;
	void loadScores();
	unsigned int _nbLvl;
	int _highScore;
};
#endif
