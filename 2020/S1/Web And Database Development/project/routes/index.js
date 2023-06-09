
var express = require('express');
var router = express.Router();

var sanitizeHtml = require('sanitize-html');

//const crypto = require('crypto');
//const uuid = require('uuid');

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('Home Page', { title: 'Home Page' });
});

router.post('/addtask', function(req, res, next) {


});

router.get('/showtasks', function(req, res, next) {


});

router.get('/userlogout', function(req, res, next) {
    //Connect to the database
    req.pool.getConnection( function(err,connection) {
        if (err) { throw err;}

        var query = "UPDATE UserProfile SET sessionflag = 0 WHERE sessionflag = 1";
        connection.query(query, function(err){
            if (err) {
                res.status(403).send();
            } else {
                console.log("logout success");
                res.send("logout successful");
            }
        });
    });
});

router.get('/userprofile', function(req, res, next) {
    //Connect to the database
    req.pool.getConnection( function(err,connection) {
        if (err) { throw err;}

    var query = "SELECT * FROM UserProfile WHERE sessionflag = 1";
        connection.query(query, function(err, rows, fields){
            connection.release();
            if (err) {
                res.status(403).send();
                return;
            }
                res.json(rows); //send response
        });
    });
});

router.get('/managerprofile', function(req, res, next) {
    //Connect to the database
    req.pool.getConnection( function(err,connection) {
        if (err) { throw err;}

    var query = "SELECT * FROM ManagerProfile WHERE sessionflag = 1";
        connection.query(query, function(err, rows, fields){
            connection.release();
            if (err) {
                res.status(403).send();
                return;
            }
            else {
                res.json(rows);
            }
        });
    });
});




module.exports = router;
