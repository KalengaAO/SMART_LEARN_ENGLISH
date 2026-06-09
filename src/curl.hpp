

size_t	write_callback(void *content, size_t memb, size_t size, void *userp)
{
	size_t	total = memb * size;

	string	*response = static_cast<string *>(userp);
	response->append(static_cast<char *>(content), total);
	return total;
}

string	requisition(string prompt){

	CURL *curl = curl_easy_init();
	char *api_key = getenv("OPENROUTER_API_KEY");
	if (!curl)
		return "Erro ao inicializar a o ambiente curl easy!";


	string	response;

	if (!api_key)
		cerr << "erro: api key invalida\n";
	json	body;
	string	res;

	body["model"] = "openai/gpt-oss-120b:free;
	body["messages"] = json::array();
	body["messages"].push_back({ {"role", "user"},
								 {"content", prompt}});
	res = body.dump();

	string	auth = "Authorization: Bearer " + string(api_key);
	struct	curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "Content-Type: application/json");
	headers = curl_slist_append(headers, auth.c_str());
	if (!headers)
		return "header não criados!";

	curl_easy_setopt(curl, CURLOPT_URL, "https://openrouter.ai/api/v1/chat/completions");
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body_json.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

	CURLcode res = curl_easy_perform(curl);

	if (res != CURLE_OK){
		curl_easy_cleanup(curl);
		curl_slist_free_all(header);
		return curl_easy_strerror(res);
	}

	curl_easy_cleanup(curl);
	curl_slist_free_all(header);

	try{
		json	data = json::parse(response);
		if (data.contains("error")){
			return data["error"]["message"].get<string>();
		}
		return data["choices"][0]
				   ["message"]
                   ["content"].get<string>();
	} catch(...){
		return "Error no parse do Json" + response;
	}
}
