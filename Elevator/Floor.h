/**
 * \file Floor.h
 *
 * \author Siyan Ma
 *
 * \brief Class that represent a floor
 */


#pragma once

#include <memory>
class CController;

/**
 * \brief Class that represent a floor
 */
class CFloor
{
public:
	CFloor();
	virtual ~CFloor();

	/** \brief Copy constructor disabled */
	CFloor(const CFloor &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CFloor &) = delete;

	void SetUp(bool up);
	void SetDown(bool down);
	void SetPanel(bool panel);

	/** \brief Set the floor number for floor
	* \param floor The floor to set */
	void SetFloor(int floor) { mFloor = floor; }

	/** \brief Get up button status in controller
	* \returns up The up button status in controller
	*/
	bool IsUp() { return mUp; }
	/** \brief Get down button status in controller
	* \returns down The down button status in controller
	*/
	bool IsDown() { return mDown; }
	/** \brief Get the panel in controller
	* \returns panel in controller
	*/
	bool IsPanel() { return mPanel; }
	/** \brief Get the floor number in floor
	* \returns floor number in controller
	*/
	int GetFloor() { return mFloor; }

	/** \brief Set the controller for floor
	* \param controller The controller to set */
	void SetController(CController *controller) { mController = controller; }

private:
	bool mUp = false;		///< Up button pressed status for this floor
	bool mDown = false;		///< down button pressed status for this floor
	bool mPanel = false;	///< panel button pressed status for this floor
	int mFloor = 0;			///< Floor number for this floor

	CController *mController;   ///< Controller for this object
};

