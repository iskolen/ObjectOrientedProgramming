#include "CController.h"

CController::CController(std::istream &input, std::ostream &output, std::vector<std::shared_ptr<CBody>>& bodies)
	: m_input(input)
	, m_output(output)
	, m_bodies(bodies)
	, m_actionMap({
		{ COMMAND_ADD_BODY, std::bind(&CController::SetNewBody, this) },
		{ COMMAND_GET_MAX_MASS_BODY, std::bind(&CController::GetMaxMassBody, this) },
		{ COMMAND_GET_LIGHTEST_BODY_IN_WATER, std::bind(&CController::GetLightestBodyInWater, this) },
		{ COMMAND_GET_INFO_ABOUT_ALL_BODIES, std::bind(&CController::GetInfoAboutAllBodies, this) }
		})
{
}

CController::~CController()
{
}


bool CController::HandleCommand()
{
	std::string commandLine;
	getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	if (!(strm >> action))
	{
		return true;
	}
	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}


double CController::SetValueDouble(const std::string& prompt)
{
	double value;
	m_output << prompt;
	while (!(m_input >> value))
	{
		m_input.clear();
		m_input.ignore(std::numeric_limits<std::streamsize>::max(), LINE_BREAK);
		m_output << ERROR_VALUE_NOT_DIGIT << std::endl;
		m_output << prompt;
	}
	return value;
}

bool CController::SetNewBody()//Паттерн пректирования - фабричный метод
{
	m_output << MESSAGE_ABOUT_TYPE_BODY;
	double bodyType = SetValueDouble(ENTER_TYPE_BODY);

	switch (static_cast<int>(bodyType))
	{
	case TYPE_BODY_SHPERE:
		return SetSphere();
	case TYPE_BODY_PARALLELEPIPED:
		return SetParallelepiped();
	case TYPE_BODY_CONE:
		return SetCone();
	case TYPE_BODY_CYLINDER:
		return SetCylinder();
	default:
		m_output << UNKNOWN_BODY_TYPE;
		return SetNewBody();
	}
}

bool CController::SetSphere()
{
	double radius = SetValueDouble(ENTER_RADIUS_SPHERE);
	double density = SetValueDouble(ENTER_DENSITY_SPHERE);

	if (radius < 0 || density < 0)
	{
		m_output << ERROR_VALUE_NEGATIVE << std::endl;
		return true;
	}

	std::shared_ptr<CSphere> sphere = std::make_shared<CSphere>(radius, density);
	m_bodies.push_back(sphere);
	m_output << BODY_SUCCESSFULLY_ADDED << std::endl;
	return true;
}

bool CController::SetParallelepiped()
{
	double width = SetValueDouble(ENTER_WIDTH_PARALLELEPIPED);
	double depth = SetValueDouble(ENTER_DEPTH_PARALLELEPIPED);
	double height = SetValueDouble(ENTER_HEIGHT_PARALLELEPIPED);
	double density = SetValueDouble(ENTER_DENSITY_PARALLELEPIPED);

	if (width < 0 || height < 0 || depth < 0 || density < 0)
	{
		m_output << ERROR_VALUE_NEGATIVE << std::endl;
		return true;
	}

	std::shared_ptr<CParallelepiped> parallelepiped = std::make_shared<CParallelepiped>(width, depth, height, density);
	m_bodies.push_back(parallelepiped);
	m_output << BODY_SUCCESSFULLY_ADDED << std::endl;
	return true;
}

bool CController::SetCone()
{
	double baseRadius = SetValueDouble(ENTER_BASE_RADIUS_CONE);
	double height = SetValueDouble(ENTER_HEIGHT_CONE);
	double density = SetValueDouble(ENTER_DENSITY_CONE);

	if (baseRadius < 0 || height < 0 || density < 0)
	{
		m_output << ERROR_VALUE_NEGATIVE << std::endl;
		return true;
	}

	std::shared_ptr<CCone> cone = std::make_shared<CCone>(baseRadius, height, density);
	m_bodies.push_back(cone);
	m_output << BODY_SUCCESSFULLY_ADDED << std::endl;
	return true;
}

bool CController::SetCylinder()
{
	double baseRadius = SetValueDouble(ENTER_BASE_RADIUS_CYLINDER);
	double height = SetValueDouble(ENTER_HEIGHT_CYLINDER);
	double density = SetValueDouble(ENTER_DENSITY_CYLINDER);

	if (baseRadius < 0 || height < 0 || density < 0)
	{
		m_output << ERROR_VALUE_NEGATIVE << std::endl;
		return true;
	}

	std::shared_ptr<CCylinder> cylinder = std::make_shared<CCylinder>(baseRadius, height, density);
	m_bodies.push_back(cylinder);
	m_output << BODY_SUCCESSFULLY_ADDED << std::endl;
	return true;
}

bool CController::GetMaxMassBody() const
{
	if (m_bodies.empty())
	{
		m_output << ERROR_BODIES_ABSENT << std::endl;
		return true;
	}

	auto maxMassBody = std::max_element(m_bodies.begin(), m_bodies.end(), [](const auto& leftBody, const auto& rightBody)
	{
		return leftBody->GetMass() < rightBody->GetMass();
	});

	GetInfoAboutBody(*maxMassBody);

	return true;
}

double CController::GetWeightBodyInWater(const std::shared_ptr<CBody>& body) const
{
	return ((body->GetDensity() - WATER_DENSITY) * ACCELERATION_OF_FREE_FALL * body->GetVolume());
}

bool CController::GetLightestBodyInWater() const
{
	if (m_bodies.empty())
	{
		m_output << ERROR_BODIES_ABSENT << std::endl;
		return true;
	}

	auto lightestBodyInWater = std::min_element(m_bodies.begin(), m_bodies.end(), [this](const auto& leftBody, const auto& rightBody)
	{
		return GetWeightBodyInWater(leftBody) < GetWeightBodyInWater(rightBody);
	});

	GetInfoAboutBody(*lightestBodyInWater);

	return true;
}

bool CController::GetInfoAboutAllBodies() const
{
	if (m_bodies.empty())
	{
		m_output << ERROR_BODIES_ABSENT << std::endl;
		return true;
	}

	for (size_t i = 0; i < m_bodies.size(); i++)
	{
		m_output << FIRST_PART_DIVISION << (i + 1) << SECOND_PART_DIVISION << m_bodies[i]->ToString() << LINE_BREAK;
	}

	return true;
}

bool CController::GetInfoAboutBody(const std::shared_ptr<CBody>& body) const
{
	if (body == nullptr)
	{
		return false;
	}
	else
	{
		m_output << body->ToString() << std::endl;
		return true;
	}
}