// Source: http://cpp-reference.ru/patterns/structural-patterns/facade/

/*
 Паттерн Facade инкапсулирует сложную подсистему в единственный интерфейсный объект.
 Это позволяет сократить время изучения подсистемы, а также способствует уменьшению
 степени связанности между подсистемой и потенциально большим количеством клиентов.
 С другой стороны, если фасад является единственной точкой доступа к подсистеме, то
 он будет ограничивать возможности, которые могут понадобиться "продвинутым"
 пользователям.

 Использование паттерна Facade
    - Определите для подсистемы простой, унифицированный интерфейс.
    - Спроектируйте класс "обертку", инкапсулирующий подсистему.
    - Вся сложность подсистемы и взаимодействие ее компонентов скрыты от клиентов.
    "Фасад" / "обертка" переадресует пользовательские запросы подходящим методам
    подсистемы.
    - Клиент использует только "фасад".
    - Рассмотрите вопрос о целесообразности создания дополнительных "фасадов".
*/


// example

#include <iostream>

class MisDepartment
{
public:
    void submitNetworkRequest()
    {
        _state = 0;
    }
    bool checkOnStatus()
    {
        _state++;
        if (_state == Complete)
            return 1;
        return 0;
    }
private:
    enum States
    {
        Received, DenyAllKnowledge, ReferClientToFacilities,
        FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
        ElectricianDidItWrong, DispatchTechnician, SignedOff,
        DoesNotWork, FixElectriciansWiring, Complete
    };
    int _state;
};

class ElectricianUnion
{
public:
    void submitNetworkRequest()
    {
        _state = 0;
    }
    bool checkOnStatus()
    {
        _state++;
        if (_state == Complete)
            return 1;
        return 0;
    }
private:
    enum States
    {
        Received, RejectTheForm, SizeTheJob, SmokeAndJokeBreak,
        WaitForAuthorization, DoTheWrongJob, BlameTheEngineer,
        WaitToPunchOut, DoHalfAJob, ComplainToEngineer,
        GetClarification, CompleteTheJob, TurnInThePaperwork,
        Complete
    };
    int _state;
};

class FacilitiesDepartment
{
public:
    void submitNetworkRequest()
    {
        _state = 0;
    }
    bool checkOnStatus()
    {
        _state++;
        if (_state == Complete)
            return 1;
        return 0;
    }
private:
    enum States
    {
        Received, AssignToEngineer, EngineerResearches,
        RequestIsNotPossible, EngineerLeavesCompany,
        AssignToNewEngineer, NewEngineerResearches,
        ReassignEngineer,EngineerReturns,
        EngineerResearchesAgain, EngineerFillsOutPaperWork,
        Complete
    };
    int _state;
};

class FacilitiesFacade
{
public:
    FacilitiesFacade()
    {
        _count = 0;
    }
    void submitNetworkRequest()
    {
        _state = 0;
    }
    bool checkOnStatus()
    {
        _count++;
        /* Запрос на обслуживание получен */
        if (_state == Received)
        {
            _state++;
            /* Перенаправим запрос инженеру */
            _engineer.submitNetworkRequest();
            std::cout << "submitted to Facilities - " << _count
                 << " phone calls so far" << std::endl;
        }
        else if (_state == SubmitToEngineer)
        {
            /* Если инженер свою работу выполнил,
               перенаправим запрос электрику */
            if (_engineer.checkOnStatus())
            {
                _state++;
                _electrician.submitNetworkRequest();
                std::cout << "submitted to Electrician - " << _count
                     << " phone calls so far" << std::endl;
            }
        }
        else if (_state == SubmitToElectrician)
        {
            /* Если электрик свою работу выполнил,
               перенаправим запрос технику */
            if (_electrician.checkOnStatus())
            {
                _state++;
                _technician.submitNetworkRequest();
                std::cout << "submitted to MIS - " << _count
                     << " phone calls so far" << std::endl;
            }
        }
        else if (_state == SubmitToTechnician)
        {
            /* Если техник свою работу выполнил,
               то запрос обслужен до конца */
            if (_technician.checkOnStatus())
                return 1;
        }
        /* Запрос еще не обслужен до конца */
        return 0;
    }
    int getNumberOfCalls()

    {
        return _count;
    }
private:
    enum States
    {
        Received, SubmitToEngineer, SubmitToElectrician,
        SubmitToTechnician
    };
    int _state;
    int _count;
    FacilitiesDepartment _engineer;
    ElectricianUnion _electrician;
    MisDepartment _technician;
};

int main()
{
    FacilitiesFacade facilities;

    facilities.submitNetworkRequest();
    /* Звоним, пока работа не выполнена полностью */
    while (!facilities.checkOnStatus())
        ;
    std::cout << "job completed after only "
         << facilities.getNumberOfCalls()
         << " phone calls" << std::endl;
}
