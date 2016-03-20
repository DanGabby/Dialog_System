# Dialog_System
<b>Диалоговые системы пятого поколения можно найти здесь.

Написано и пишется на QT C++.

<b>17.03

HashTable — моя реализация хеш-таблицы. Сейчас может хранить только SemNetObj. Можно сделать её универсальной через template, но зачем?

SemNetObj определяет семейство классов, экземпляры которых могут лежать в таблице. При получении из таблицы, их не нужно никак обрабатывать. 
Объект "уже знает" своё предназначение и имеет единственный метод — "выполнить своё предназначение". Аргументом методу передаётся DataSender.
DataSender порождает сигналы, обрабатываемые View. Таким образом объект передаёт запрашиваемые пользователем данные.

MVP:

Model объединяет объекты, отвечающие за: способ хранения диалога, получения следующего вопроса, передачу данных во View. Приём данных из View происходит благодаря Слоту модели. Т.е. Модель и Представление обмениваются данными через систему сигнал-слотов. Presenter раньше содержал серьёзный набор методов для обеспечения связи между Model и View. Теперь его функция в одном: наладить связь connection между Сигналами и слотами Модели и Представления (на момент комита работаю над этим, проект собирается, но теперь я ловлю SIGSEV Segmentation fault).

Осталось написать серелизатор и десериализатор для сценариев диалога. И можно в продакшн.

<b>19.03

Программа заработала...

HashTable предана забвению. Для хранения диалога теперь используется QHash.

Изменены типы, описывающие "вопрос" и "список ответов" со string и string[NUMBEROFANSWERS] на QString и QList<QString>. Переписаны методы консольной View: вместо cin cout используется QTextStream.

Добавлены сигналы и слоты отвечающие за начало и конец работы диалоговой системы. DataSender переименован в SignalSender, теперь он
будет содержать все сигналы модели.

До сих пор не нашёл способа выйти из QCoreApplication цикла, пытался передавать этот объект по ссылке и вызывать методы exit и quit 
внутри слота, отвечающего за конец работы. Безрезультатно.

Фиксы, связанные с интерфейсом DialogStructure (если понадобится, сделаю интерфейс и DialogWorker'а)

Переделал структуру проекта. Распихал по папкам, перекинул связи. Теперь приходится подключать #include"ПАПКА/заголовочный файл".
С одной стороны стоит сделать для каждой папки файл, в котором include все заголовочные файлы папки и в работе использовать эти
крупноблочные include. С другой стороны, явно показано, с чем связан подключаемый код...

Презентер стал совсем тонким, а бизнес-логика размазалась по всей программе и стекла в сигналы и слоты. Можно попробовать перетащить 
сигналы и слоты в Презентер, а Модели и Представлению для работы с ними дать интерфейсные методы (что имеет смысл). Но это повлечёт за собой определённый каскадный рефакторинг. Ничего особенно сложного, но нужно ли это? (посидел, подумал, похоже, что нужен, но сейчас чуть ли не каждый класс имеет над собой абстракцию в виде интерфейса... ОСТАНОВИСЬ, ПОДУМАЙ)

Серелизатора и десерелизатор всё ещё нет. Заглушил метод Init класса DialogStructure, который инициализирует модель диалогом, достаточным для тестов и дебага.
