var mysql = require('mysql');
var express = require('express');
var session = require('express-session');
var logger = require('morgan');
var bodyParser = require('body-parser');
var cookieParser = require('cookie-parser');
var path = require('path');

var sanitizeHtml = require('sanitize-html');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');

var connection = mysql.createPool({
   host     : 'localhost',
   database : 'taskmanager'
});

var app = express();

app.use(session({
	secret: 'secret',
	resave: true,
	saveUninitialized: true
}));

app.use(function(req, res, next){
    req.pool = connection;
    next();
});

app.use(bodyParser.urlencoded({extended : true}));
app.use(bodyParser.json());

app.post('/login', function(req, res, next) {
	var username = sanitizeHtml(req.body.username);
	var password = sanitizeHtml(req.body.password);

	if (username && password) {
		// user login
		connection.query('SELECT * FROM UserProfile WHERE username = ? AND password = ?', [username, password], function(error, results, fields) {
			if (results.length > 0) {
				connection.query("UPDATE UserProfile SET sessionflag = 1 WHERE username = ?", [username], function(error, results, fields){
				});
					req.session.loggedin = true;
					req.session.username = username;
					res.redirect('/user.html');
			} else if (results.length < 0 ){
				// manager login
				connection.query('SELECT * FROM ManagerProfile WHERE username = ? AND password = ?', [username, password], function(error, results, fields) {
				if (results.length > 0) {
					connection.query("UPDATE ManagerProfile SET sessionflag = 1 WHERE username = ?", [username], function(error, results, fields){
					});
						req.session.loggedin = true;
						req.session.username = username;
						res.redirect('/manager.html');
				}
				else {
					res.send('Incorrect Username and/or Password!');
				}
			});
			} else {
				res.send('Incorrect Username and/or Password!');
			}
			res.end();
		});
	} else {
		res.send('Please enter Username and Password!');
		res.end();
	}
});

app.post('/signup', function(req, res, next) {

    var username = sanitizeHtml(req.body.username);
	var password = sanitizeHtml(req.body.password);
	var flag = sanitizeHtml(req.body.position);
	//console.log(username);
	//console.log(pass);
	//console.log(flag);

	//var userradio = document.getElementById('userradio').value;
    req.pool.getConnection( function(err,connection) {
	if (err) {
		res.sendStatus(500);
		return;
    }
	if (flag === "1") { // user selected
		if (username && password) {
			connection.query('SELECT * FROM UserProfile WHERE username = ?', [username], function(error, results, fields) {
				if (results.length > 0) {
					res.send('this account already exists');
					return;
				} else {
					connection.query("INSERT INTO UserProfile (username, password, sessionflag, age, email, department ) VALUES(?, ?, 1, 20, 'blank', 'blank')", [username, password], function(error, results, fields){
					});
				}
				res.redirect('/user.html');
				res.end();
			});
		} else {
			res.send('erro2');
			res.end();
		}
	}
	else if (flag === "2") { //manager selected
		if (username && password) {
			connection.query('SELECT * FROM ManagerProfile WHERE username = ?', [username], function(error, results, fields) {
				if (results.length > 0) {
					res.send('this account already exists');
					return;
				} else {
					connection.query("INSERT INTO ManagerProfile (username, password, sessionflag, age, email, department ) VALUES(?, ?, 1, 20, 'blank', 'blank')", [username, password], function(error, results, fields){
				});
				}
				res.redirect('/manager.html');
				res.end();
			});
		} else {
			res.send('erro2');
			res.end();
		}
	}
	else {
		res.send('Please Select a Role.');
	}
   });
});

app.post('/updateuserprofile', function(req, res, next) {

    var name = sanitizeHtml(req.body.name);
    var age = sanitizeHtml(req.body.age);
    var bio = sanitizeHtml(req.body.bio);
	//console.log(name);
	//console.log(age);
    //Connect to the database
    req.pool.getConnection( function(err,connection) {
    if (err) {
      res.sendStatus(500);
      return;
    }
        if (name && age) {
        connection.query("UPDATE UserProfile SET username = ? , age = ?, bio = ? WHERE sessionflag = 1", [name, age, bio], function(err, rows, fields){
            if (err) {
                res.status(403).send();
            return;
            } else {
                res.redirect('/userprofile.html');
            }
        });
        }
        else {
            res.send("update user profile fail");
        }
    });
});

app.post('/updatemanagerprofile', function(req, res, next) {

    var name = sanitizeHtml(req.body.name);
    var age = sanitizeHtml(req.body.age);
    var bio = sanitizeHtml(req.body.bio);
	//console.log(name);
	//console.log(age);
    //Connect to the database
    req.pool.getConnection( function(err,connection) {
    if (err) {
      res.sendStatus(500);
      return;
    }
        if (name && age) {
        connection.query("UPDATE ManagerProfile SET username = ? , age = ?, bio = ? WHERE sessionflag = 1", [name, age, bio], function(err, rows, fields){
            if (err) {
                res.status(403).send();
            return;
            } else {
                res.redirect('/managerprofile.html');
            }
        });
        }
        else {
            res.send("update manager profile fail");
        }
    });
});

//update user avaliability
app.post('/updateavaliability', function(req, res, next) {

	var avaldate = req.body.avaldate;
	console.log(avaldate);
	req.pool.getConnection( function(err,connection) {
		if (err) {
		res.sendStatus(500);
		return;
    }
    if(avaldate){
		connection.query("UPDATE User SET NotAvaliable = ? WHERE sessionflag = 1", [avaldate], function(err, rows, fields){
			if (err) {
                res.status(403).send();
            return;
            } else {
                res.redirect('/user.html');
            }
		});
    }
    else {
		res.status(403).send();
    }
	});
});

//update user avaliability
app.post('/userfunctions', function(req, res, next) {
	var task = req.body.task;
	var taskid = req.body.taskid;
	var involvement = req.body.involvement;
	var completeflag = req.body.completeflag;

	req.pool.getConnection( function(err,connection) {
		if (err) {
		res.sendStatus(500);
		return;
    }
    if (involvement){
	connection.query("UPDATE User SET AssignedTasks = ? WHERE sessionflag = 1", [task], function(err, rows, fields){
			if (err) {
                res.status(403).send();
            return;
            } else {
                res.redirect('/user.html');
            }
        });
    }
    if (completeflag){
		connection.query("UPDATE Task SET Complete = 1 WHERE TaskID = ?", [taskid], function(err, rows, fields){
			if (err) {
                res.status(403).send();
            return;
            } else {
                res.redirect('/user.html');
			}
		});
    }
    else {
		res.status(412).send();
    }
	});
});

app.listen(3000);

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);

module.exports = app;
