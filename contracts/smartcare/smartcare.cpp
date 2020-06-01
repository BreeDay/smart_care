#include "smartcare.hpp"

ACTION smartcare::login(name username) {
  // Ensure this action is authorized by the player
  require_auth(username);
  
  // Create a record in the table if the user doesn't exist in our app yet
  auto user_iterator = _users.find(username.value);
  if (user_iterator == _users.end()) {
    user_iterator = _users.emplace(username,  [&](auto& new_user) {
      new_user.username = username;
    });
  } 
}

ACTION smartcare::clear() {
  require_auth(get_self());

  // Delete all records in _users table
  auto user_itr = _users.begin();
  while (user_itr != _users.end()) {
    user_itr = _users.erase(user_itr);
  }
}

ACTION smartcare::accesspdata(name username, uint16_t patient_id) {
  require_auth(username);


}

EOSIO_DISPATCH(healthkeeper, (login)(clear)(accesspdata))
