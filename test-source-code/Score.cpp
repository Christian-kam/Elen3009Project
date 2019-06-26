#include "Score.h"

Score::Score():_filename{"highscore.txt"}, _infile{_filename.c_str()}, _score{0} 
{
    // in infile's constructor (called above in the memberwise initialisation list)
	// the input file stream is associated with a text file
	if ( !_infile )
		throw FileCannotBeOpened();

    loadScores();
}

void Score::updateScore(ID item)
{
    if(item == ID::lander)
    {
        _score += 150;
    }
    else if(item == ID::powerUp)
    {
        _score += 1000;
    }
    else if(item == ID::playerSmartBomb)
    {
        _score += 500;
    }
}

const int Score::getScore() const
{
    return _score;

}

const int  Score::getHighScore() const
{
    return _highScore;
}

void Score::loadScores()
{
	_infile >> _highScore;
    _infile.close();
}

void Score::WriteScore()
{
    if (_score > _highScore)
    {
        std::ofstream _outfile{_filename.c_str()};
        _outfile << _score;
        
    }
}





