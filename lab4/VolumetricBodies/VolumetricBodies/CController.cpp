#include "CController.h"

CController::CController(std::istream &input, std::ostream &output)
	: m_input(input)
	, m_output(output)
{
}

//Использовать алгоритмы stl (min, max)
void CController::PrintStartMessage()
{
	std::cout << START_MESSAGE;
}

double CController::ReadValueDouble(const std::string& prompt)
{
	double value;
	std::cout << prompt;
	std::cin >> value;
	return value;
}

int CController::ReadValueInt(const std::string& prompt)
{
	int value;
	std::cout << prompt;
	std::cin >> value;
	return value;
}

void CController::AddBodyToCompound(std::shared_ptr<CCompound>& compound)
{
	int bodyType;
	std::cout << MESSAGE_ABOUT_TYPE_BODY;
	std::cout << ENTER_TYPE_BODY;
	std::cin >> bodyType;

	if (bodyType == TYPE_BODY_SHPERE)
	{
		double radius = ReadValueDouble(ENTER_RADIUS_SPHERE);
		double density = ReadValueDouble(ENTER_DENSITY_SPHERE);
		std::shared_ptr<CSphere> sphere = std::make_shared<CSphere>(radius, density);
		compound->AddChildBody(sphere);
		return;
	}
	if (bodyType == TYPE_BODY_PARALLELEPIPED)
	{
		double width = ReadValueDouble(ENTER_WIDTH_PARALLELEPIPED);
		double depth = ReadValueDouble(ENTER_DEPTH_PARALLELEPIPED);
		double height = ReadValueDouble(ENTER_HEIGHT_PARALLELEPIPED);
		double density = ReadValueDouble(ENTER_DENSITY_PARALLELEPIPED);
		std::shared_ptr<CParallelepiped> parallelepiped = std::make_shared<CParallelepiped>(width, depth, height, density);
		compound->AddChildBody(parallelepiped);
		return;
	}
	if (bodyType == TYPE_BODY_CONE)
	{
		double baseRadius = ReadValueDouble(ENTER_BASE_RADIUS_CONE);
		double height = ReadValueDouble(ENTER_HEIGHT_CONE);
		double density = ReadValueDouble(ENTER_DENSITY_CONE);
		std::shared_ptr<CCone> cone = std::make_shared<CCone>(baseRadius, height, density);
		compound->AddChildBody(cone);
		return;
	}
	if (bodyType == TYPE_BODY_CYLINDER)
	{
		double baseRadius = ReadValueDouble(ENTER_BASE_RADIUS_CYLINDER);
		double height = ReadValueDouble(ENTER_HEIGHT_CYLINDER);
		double density = ReadValueDouble(ENTER_DENSITY_CYLINDER);
		std::shared_ptr<CCylinder> cylinder = std::make_shared<CCylinder>(baseRadius, height, density);
		compound->AddChildBody(cylinder);
		return;
	}
}

void CController::AddBody(std::vector<std::shared_ptr<CBody>>& bodies)
{
	int bodyType;
	std::cout << MESSAGE_ABOUT_TYPE_BODY;
	std::cout << ENTER_TYPE_BODY;
	std::cin >> bodyType;

	if (bodyType == TYPE_BODY_SHPERE)
	{
		double radius = ReadValueDouble(ENTER_RADIUS_SPHERE);
		double density = ReadValueDouble(ENTER_DENSITY_SPHERE);
		std::shared_ptr<CSphere> sphere = std::make_shared<CSphere>(radius, density);
		bodies.push_back(sphere);
		return;
	}
	if (bodyType == TYPE_BODY_PARALLELEPIPED)
	{
		double width = ReadValueDouble(ENTER_WIDTH_PARALLELEPIPED);
		double depth = ReadValueDouble(ENTER_DEPTH_PARALLELEPIPED);
		double height = ReadValueDouble(ENTER_HEIGHT_PARALLELEPIPED);
		double density = ReadValueDouble(ENTER_DENSITY_PARALLELEPIPED);
		std::shared_ptr<CParallelepiped> parallelepiped = std::make_shared<CParallelepiped>(width, depth, height, density);
		bodies.push_back(parallelepiped);
		return;
	}
	if (bodyType == TYPE_BODY_CONE)
	{
		double baseRadius = ReadValueDouble(ENTER_BASE_RADIUS_CONE);
		double height = ReadValueDouble(ENTER_HEIGHT_CONE);
		double density = ReadValueDouble(ENTER_DENSITY_CONE);
		std::shared_ptr<CCone> cone = std::make_shared<CCone>(baseRadius, height, density);
		bodies.push_back(cone);
		return;
	}
	if (bodyType == TYPE_BODY_CYLINDER)
	{
		double baseRadius = ReadValueDouble(ENTER_BASE_RADIUS_CYLINDER);
		double height = ReadValueDouble(ENTER_HEIGHT_CYLINDER);
		double density = ReadValueDouble(ENTER_DENSITY_CYLINDER);
		std::shared_ptr<CCylinder> cylinder = std::make_shared<CCylinder>(baseRadius, height, density);
		bodies.push_back(cylinder);
		return;
	}
	if (bodyType == TYPE_BODY_COMPOUND)
	{
		int numBodies = ReadValueInt(ENTER_NUMBER_OF_BODIES);
		std::shared_ptr<CCompound> compound = std::make_shared<CCompound>();
		bodies.push_back(compound);
		for (int i = 0; i < numBodies; i++)
		{
			AddBodyToCompound(compound);
		}
	}
	else
	{
		std::cout << UNKNOWN_BODY_TYPE;
	}
}

void CController::FindMaxMassBody(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	double maxMass = 0;
	std::shared_ptr<CBody> maxMassBody;

	if (!bodies.empty())
	{
		for (auto body : bodies)
		{
			if (body->GetMass() > maxMass)
			{
				maxMass = body->GetMass();
				maxMassBody = body;
			}
		}
		std::cout << MESSAGE_MAX_MASS_BODY << maxMassBody->ToString() << std::endl;
	}
}

double CController::GetWeightBodyInWater(std::shared_ptr<CBody>& body)
{
	return ((body->GetDensity() - WATER_DENSITY) * ACCELERATION_OF_FREE_FALL * body->GetVolume());
}

void CController::FindLightestBodyInWater(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	double minWeightInWater = MIN_WEIGHT_IN_WATER;
	std::shared_ptr<CBody> minWeightInWaterBody;

	if (!bodies.empty())
	{
		for (auto body : bodies)
		{
			if (GetWeightBodyInWater(body) < minWeightInWater)
			{
				minWeightInWater = GetWeightBodyInWater(body);
				minWeightInWaterBody = body;
			}
		}
		std::cout << MESSAGE_MIN_WEIGHT_IN_WATER << minWeightInWaterBody->ToString() << LINE_BREAK;
		std::cout << MESSAGE_WEIGHT_IN_WATER << minWeightInWater;
	}
}

void CController::GetInfoAboutAllBodies(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	if (!bodies.empty())
	{
		for (int i = 0; i < bodies.size(); i++)
		{
			std::cout << FIRST_PART_DIVISION << (i + 1) << SECOND_PART_DIVISION << bodies[i]->ToString() << LINE_BREAK;
		}
	}
}