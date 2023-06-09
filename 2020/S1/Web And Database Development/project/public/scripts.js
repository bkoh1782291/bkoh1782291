
function darkmode() {
   var element = document.body;
   element.classList.toggle("dark-mode");
}


function scrollingheader() {
    var header = document.getElementById("myHeader");
    var sticky = header.offsetTop;

    if (window.pageYOffset > sticky) {
      header.classList.add("sticky");
    } else {
      header.classList.remove("sticky");
    }
}

function buttoncolor(){

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "/home.html", true);

    xhttp.send();

    xhttp.onreadystatechange = function(){
     if (this.readyState == 4 && this.status == 200){

          var changecolor = document.getElementById("priority");
          changecolor.innerHTML = this.responseText;
          changecolor.style.color = this.responseText ;

        }
    };
}

/* AJAX Login */
// gets login info and checks if username and password is stored


function loginredirect(){

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "/login.html", true);
    xhttp.send();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            window.location.replace("/login.html");
        }
    };
}


/* AJAX Signup */
// gets account info and stores into database
// takes in the radio button of making either manager or user account
function signupredirect(){

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "/signup.html", true);
    xhttp.send();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            window.location.replace("/signup.html");
        }
    };
}

// function for "back to home" buttons
function homeredirect(){

    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/", true);
    xhttp.send();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            window.location.replace("/");
        }
    };
}

// function for "back to home" buttons for users
function userredirect(){
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/", true);
    xhttp.send();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            window.location.replace("/user.html");
        }
    };
}

// function for "back to home" buttons for managers
function managerredirect(){
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/", true);
    xhttp.send();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            window.location.replace("/manager.html");
        }
    };
}

//function for popups
function popupbtnright() {
  var popupright = document.getElementById("myPopupright");
  popupright.classList.toggle("show");
}

function popupbtnleft() {
  var popupleft = document.getElementById("myPopupleft");
  popupleft.classList.toggle("show");
}

function userprofile(){

    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/userprofile.html", true);
    xhttp.send();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            window.location.replace("/userprofile.html");
        }
    };
}

function managerprofile(){

    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/managerprofile.html", true);
    xhttp.send();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            window.location.replace("/managerprofile.html");
        }
    };
}

/* google openID sign in/out */
function onSignIn(googleUser) {
      var profile = googleUser.getBasicProfile();
      console.log('ID: ' + profile.getId()); // Do not send to your backend! Use an ID token instead.
      console.log('Name: ' + profile.getName());
      console.log('Image URL: ' + profile.getImageUrl());
      console.log('Email: ' + profile.getEmail()); // This is null if the 'email' scope is not present.

      var id_token = googleUser.getAuthResponse().id_token;

      var xhr = new XMLHttpRequest();
      xhr.open('POST', '/tokensignin');

      xhr.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            window.location.replace("/user.html");
        } else  if (this.readyState == 4 && this.status == 401) {
          // login failed
        }
      };

      window.location.replace("/user.html");
      xhr.setRequestHeader('Content-Type', 'application/json');
      xhr.send(JSON.stringify({'idtoken': id_token}));
}

function signOut() {
  var auth2 = gapi.auth2.getAuthInstance();
  auth2.signOut().then(function () {
    console.log('User signed out.');
  });
  // Do our logout on server here
}

function LogOut(){

    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            // logout and sql update sessionflag
             window.location.replace("/home.html");
        }
    };

    xhttp.open("GET", "/userlogout", true);
    xhttp.send();
}


// load profile info
function loaduserProfile(){

    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            var users = JSON.parse(this.responseText);
            var role = "User";
            document.getElementById("userprofilename").innerHTML = users[0].username;
            document.getElementById("userprofilerole").innerHTML = role;
            document.getElementById("userprofilebio").innerHTML = users[0].bio;
            document.getElementById("userprofileage").innerHTML = users[0].age;
        }
    };
    xhttp.open("GET", "/userprofile", true);
    xhttp.send();
}


// load manager info
function loadmanagerProfile(){

    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            var managers = JSON.parse(this.responseText);
            var role = "Manager";
            document.getElementById("managerprofilename").innerHTML = managers[0].username;
            document.getElementById("managerprofilerole").innerHTML = role;
            document.getElementById("managerprofilebio").innerHTML = users[0].bio;
            document.getElementById("userprofileage").innerHTML = managers[0].age;
        }
    };
    xhttp.open("GET", "/managerprofile", true);
    xhttp.send();
}

function profilediv() {
    var x = document.getElementById("profilediv");

    if (x.style.display === "none") {
        x.style.display = "block";
    } else {
        x.style.display = "none";
    }
}

/*
function signup(){

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "/signup.html", true);

    xhttp.send();

    xhttp.onreadystatechange = function(){
     if (this.readyState == 4 && this.status == 200){


        }
    };
}


function manager(){

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "/signup.html", true);

    xhttp.send();

    xhttp.onreadystatechange = function(){
     if (this.readyState == 4 && this.status == 200){


        }
    };
}


function user(){

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "/signup.html", true);

    xhttp.send();

    xhttp.onreadystatechange = function(){
     if (this.readyState == 4 && this.status == 200){


        }
    };
}


function updatetasks(){

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "/signup.html", true);

    xhttp.send();

    xhttp.onreadystatechange = function(){
     if (this.readyState == 4 && this.status == 200){


        }
    };
}


function updateinvolvement(){

    var xhttp = new XMLHttpRequest();

    xhttp.open("GET", "/signup.html", true);

    xhttp.send();

    xhttp.onreadystatechange = function(){
     if (this.readyState == 4 && this.status == 200){


        }
    };
}

*/

var deletetask = new Vue({
    el: "#deletetask",
    data: {
        checkedTasks: [],
    }
});

var newtask = new Vue({
  el: '#newtask',
  data: {
    checkedNames: [],
    message: ""
  }
});

var newgroupedtask = new Vue({
    el: "#newgroupedtask",
    data: {
        grouptaskname: "",
        checkedUsers: []
    }
});

var managerprofile = new Vue({
    el: "#managerprofile",
    data: {
        items: [
          { people: 'Brian' },
          { people: 'John' },
          { people: 'Irvin' }
        ]
    }
});

var userprofile = new Vue({
    el: "#userprofile",
    data: {
        items: [
          { people: 'Server Backend Fix' },
          { people: 'Server Frontend Fix' },
          { people: 'Database Backup' }
        ]
    }
});