#include "hiq/game/CarGame.h"

#include "hiq/board/board.h"
#include "hiq/command/CarCmdExecutor.h"
#include "hiq/geometry/Direction.h"
#include "hiq/geometry/Point2D.h"
#include "hiq/vehicle/Car.h"
#include "utils/utils.h"

#include <iostream>

using namespace hiq::board;
using namespace hiq::command;
using namespace hiq::geometry;
using namespace hiq::vehicle;

namespace hiq {
namespace game { 

Point2D CarGame::convertStartingPoint(const std::string& x,
                                      const std::string& y)
{
    Point2D position{-1, -1};
    try
    {
        position.x = std::stoi(x);
        position.y = std::stoi(y);
    }
    catch(const std::invalid_argument& e)
    {
        throw(e);
    }
    catch(const std::out_of_range& e)
    {
        throw(e);
    }
    if(position.x < 1 || position.y < 1)
    {
        const std::string error{"Invalid starting point (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")"};
        throw(std::runtime_error(error.c_str()));
    }

    return position;
}

Point2D CarGame::convertBoardDims(const std::string& x,
                                  const std::string& y)
{
    Point2D dims{-1, -1};
    try
    {
        dims.x = std::stoi(x);
        dims.y = std::stoi(y);
    }
    catch(const std::invalid_argument& e)
    {
        throw(e);
    }
    catch(const std::out_of_range& e)
    {
        throw(e);
    }
    if(dims.x < 1 || dims.y < 1)
    {
        const std::string error{"Unsupported dimensions (width: " + std::to_string(dims.x) + ", height: " + std::to_string(dims.y) + ")"};
        throw(std::runtime_error(error.c_str()));
    }

    return dims;
}

Direction CarGame::convertDirection(const std::string& direction)
{
    if(direction == "N")
    {
        return Direction::NORTH;
    }
    else if(direction == "E")
    {
        return Direction::EAST;
    }
    else if(direction == "S")
    {
        return Direction::SOUTH;
    }
    else if(direction =="W")
    {
        return Direction::WEST;
    }
    else 
    {
        const std::string error{"Unsupported heading direction: " + direction};
        throw(std::runtime_error(error.c_str()));
    }
}

std::vector<std::string> CarGame::getInput(const size_t expectedNrInputs)
{
    const auto input{utils::askInput()};
    const auto inputTokens{utils::splitInput(input, ' ')};
    
    if(inputTokens.size() != expectedNrInputs)
    {
        const std::string error{"Unexpected number of tokens. Expected: " + std::to_string(expectedNrInputs) + ", received: " + std::to_string(inputTokens.size())};
        throw(std::runtime_error(error.c_str()));
    }

    return inputTokens;
}

Point2D CarGame::getBoardDimensions()
{
    std::cout << "Input the width and height of the room (W H): ";

    try 
    {
        const auto tokens{getInput(2)};
        const auto boardDims = convertBoardDims(tokens[0], tokens[1]);

        return boardDims;
    }
    catch(const std::runtime_error& e)
    {
        throw(std::runtime_error(e));
    }

}

std::pair<Point2D, Direction> CarGame::getVehicleStartPosition()
{
    std::cout << "Input the cars starting position (X Y Direction): ";
    try
    {   
        const auto tokens{getInput(3)};
        const auto carPosition{convertStartingPoint(tokens[0], tokens[1])};
        const auto direction{convertDirection(tokens[2])};
        if(!m_upBoard->isInside(carPosition))
        {
            const std::string error{"Car starting outside of map at (" + std::to_string(carPosition.x) + ", " + std::to_string(carPosition.y) + ")"};
            throw(std::runtime_error(error.c_str()));
        }
        return {carPosition, direction};
    }
    catch(const std::runtime_error& e)
    {
        throw(std::runtime_error(e));
    }

}

void CarGame::createBoard()
{
    try
    {
        const auto boardDims{getBoardDimensions()};
        m_upBoard = std::make_unique<Board>(boardDims.x, boardDims.y);
    }
    catch(const std::runtime_error& e)
    {
        throw(std::runtime_error(e));
    }
}

void CarGame::createCar()
{
    try 
    {
        const auto carStartPos{getVehicleStartPosition()};
        m_spVehicle = std::make_shared<Car>(carStartPos.first, carStartPos.second);
    }
    catch(const std::runtime_error& e)
    {
        throw(std::runtime_error(e));
    }
}

void CarGame::createCmdExecutor()
{
    m_upCmdExecutor = std::make_unique<CarCmdExecutor>();
}

void CarGame::executeCommands(const std::string& commands)
{
    try 
    {
        for(const auto& command : commands)
        {
            m_upCmdExecutor->performAction(m_spVehicle, command);
            const auto currentPosition{m_spVehicle->getPosition()};
            if(!m_upBoard->isInside(currentPosition))
            {
                std::string error{"Collision at (" + std::to_string(currentPosition.x) + ", " + std::to_string(currentPosition.y) + ")"};
                throw(std::runtime_error(error.c_str()));
            }
        }
    }
    catch(std::runtime_error& e)
    {
        throw(e);
    }
}

void CarGame::run()
{
    try 
    {
        createBoard();
        createCar();
    }
    catch(std::runtime_error& e)
    {
        throw(e);
    }

    createCmdExecutor();
    std::cout << "Input commands: ";
    const auto& commands{utils::askInput()};
    
    try 
    {
        executeCommands(commands);
    }
    catch(std::runtime_error& e)
    {
        throw(e);
    }

    const auto finalPos{m_spVehicle->getPosition()};
    const auto finalDir{m_spVehicle->getDirection()};
    const std::string finalDirStr{finalDir == Direction::NORTH ? "north\0" 
                         : finalDir == Direction::EAST  ? "east\0"
                         : finalDir == Direction::SOUTH ? "south\0"
                         : "west\0"};
    std::cout << "Final position: (" << finalPos.x << ", " << finalPos.y << ")\n" << "Heading: " << finalDirStr << "\n";
}

} // namespace game
} // namespace hiq
