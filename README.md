# Практическая работа № 5
* Создайте класс BankAccount, представляющий простой банковский счет. Класс должен иметь следующие приватные переменные:accountNumber (int), balance (double), interestRate (double), то есть номер банковского счёта, баланс и процентная ставка.
* Класс также должен иметь общедоступные функции: внести средства на счет (deposit), снять средства со счета (withdraw), рассчитать и вернуть текущий баланс (getBalance), рассчитать и вернуть сумму процентов, заработанных на счете (getInterest), обновить процентную ставку (setInterestRate), получить номер банковского счёта (getAccountNumber)
* Полученные проценты должны рассчитываться с использованием простой процентной формулы: проценты = остаток * процентная ставка * (1 / 12).
* В классе должен быть конструктор, который принимает номер счета и начальный баланс в качестве параметров и устанавливает процентную ставку на 0.
* Класс также должен иметь дружественную функцию (трансфер (transfer)), который принимает три объекта - два номера банковского счёта и сумму перевода в качестве параметров и переводит указанную сумму с одного счета на другой. Она должна возвращать true, если перевод был успешным (т. е. если на первом счете было достаточно средств для покрытия перевода), и false в противном случае.
* Сделать проверку на ошибки (проверка на так называемого «дурака»)
* Использовать локализацию, комментарии ключевое слово this
