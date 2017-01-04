CREATE TABLE Answers
(
	id INTEGER,
	answer_text TEXT NOT NULL,
	question_id INTEGER NOT NULL,
	CONSTRAINT PK_Answers PRIMARY KEY (id),
	CONSTRAINT FK_Answers_Questions FOREIGN KEY (question_id)
		REFERENCES Questions(id) ON DELETE NO ACTION ON UPDATE RESTRICT
)
;

CREATE TABLE ConcreteTests
(
	id INTEGER,
	test_id INTEGER NOT NULL,
	user_who_started INTEGER NOT NULL,
	name TEXT NOT NULL,
	datetime_created TEXT DEFAULT(datetime('now')) NOT NULL,
	CONSTRAINT PK_ConcreteTests PRIMARY KEY (id),
	CONSTRAINT FK_ConcreteTests_Tests FOREIGN KEY (test_id)
		REFERENCES Tests(id) ON DELETE RESTRICT ON UPDATE RESTRICT
)
;

CREATE TABLE Logs
(
	id INTEGER,
	answer_id INTEGER NOT NULL,
	concrete_test_id INTEGER NOT NULL,
	datetime_created TEXT DEFAULT(datetime('now')),
	CONSTRAINT PK_Logs PRIMARY KEY (id),
	CONSTRAINT FK_Logs_Answers FOREIGN KEY (answer_id)
		REFERENCES Answers(id) ON DELETE RESTRICT ON UPDATE RESTRICT,
	CONSTRAINT FK_Logs_Answers FOREIGN KEY (answer_id)
		REFERENCES Answers(id) ,
	CONSTRAINT FK_Logs_ConcreteTests FOREIGN KEY (concrete_test_id)
		REFERENCES ConcreteTests(id) ON DELETE RESTRICT ON UPDATE RESTRICT
)
;

CREATE TABLE Questions
(
	id INTEGER,
	question_text TEXT NOT NULL,
	correct_answer INTEGER,
	test_id INTEGER NOT NULL,
	CONSTRAINT PK_Questions PRIMARY KEY (id),
	CONSTRAINT FK_Questions_Answers FOREIGN KEY (correct_answer)
		REFERENCES Answers(id) ON DELETE RESTRICT ON UPDATE RESTRICT DEFERRABLE INITIALLY DEFERRED,
	CONSTRAINT FK_Questions_Answers FOREIGN KEY (correct_answer)
		REFERENCES Answers(id) ,
	CONSTRAINT FK_Questions_Tests FOREIGN KEY (test_id)
		REFERENCES Tests(id) ON DELETE RESTRICT ON UPDATE RESTRICT
)
;

CREATE TABLE Tests
(
	id INTEGER,
	name TEXT NOT NULL,
	user_who_made INTEGER NOT NULL,
	UNIQUE(name, user_who_made),
	CONSTRAINT PK_Tests PRIMARY KEY (id),
	CONSTRAINT FK_Tests_Users FOREIGN KEY (user_who_made)
		REFERENCES Users(id) ON DELETE RESTRICT ON UPDATE RESTRICT
)
;

CREATE TABLE Users
(
	id INTEGER,
	name TEXT UNIQUE NOT NULL,
	datetime_created TEXT NOT NULL DEFAULT(datetime('now')),
	CONSTRAINT PK_Users PRIMARY KEY (id)
)
;


CREATE INDEX index_question_id
ON Answers (question_id ASC)
;

CREATE INDEX index_answer_id
ON Logs (answer_id ASC)
;

CREATE INDEX index_concrete_test_id
ON Logs (concrete_test_id ASC)
;

CREATE INDEX index_datetime_created
ON Logs (datetime_created ASC)
;

CREATE INDEX index_test_id
ON Questions (test_id ASC)
;
