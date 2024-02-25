#pragma once

#include "hiq/board/board.h"
#include "hiq/command/ICommandExecutor.h"
#include "hiq/geometry/Point2DFwd.h"
#include "hiq/game/IGame.h"
#include "hiq/vehicle/IVehicle.h"

#include <memory>
#include <vector>

namespace hiq {
namespace game {

class CarGame : public IGame {
public:
    CarGame() = default;

    void run() final;

private:
    geometry::Point2D convertStartingPoint(const std::string& x, const std::string& y);
    geometry::Point2D convertBoardDims(const std::string& x, const std::string& y);
    geometry::Direction convertDirection(const std::string& direction);
    geometry::Point2D getBoardDimensions();

    void createBoard();
    void createCar();
    void createCmdExecutor();
    void executeCommands(const std::string& commands);

    std::pair<geometry::Point2D, geometry::Direction> getVehicleStartPosition();
    std::vector<std::string> getInput(const size_t expectedNrInputs);

    std::unique_ptr<command::ICommandExecutor> m_upCmdExecutor;
    std::shared_ptr<vehicle::IVehicle> m_spVehicle;
    std::unique_ptr<board::Board> m_upBoard;
};

} // namespace game
} // namespace hiq
